/*!
 * uart.h
 * 
 * \brief		DESCRIPTION
 *
 * \detailed	DETAILED
 *
 *	\author		Hauke Petersen
 *  \date 		Jul 31, 2013
 */

/* Includes ------------------------------------------------------------------*/
#include "uart.h"
#include "util.h"
#include "hw_mapping.h"

/* Module enabler ------------------------------------------------------------*/
#ifdef MODULE_UART_EN

/* Private typedefs ----------------------------------------------------------*/
typedef struct {
	uart_channel_t channel;
	uint32_t baudrate;

	void(*done_sending_callback)();
	void(*received_callback)(uint8_t*, uint8_t);
} uart_t;

typedef struct {
	uart_channel_t channel;
	uint32_t baudrate;
} uart_init_t;

/* Private defines -----------------------------------------------------------*/
#define UART_CHANNELS		2		// the target device has two uart channels

//#define UART_C1_EN			1
//#define UART_C2_EN			0

/* Private macros ------------------------------------------------------------*/
#define UART_CHANNEL(c)
#define port(c)				uart ## c

/* Private variables ---------------------------------------------------------*/
#ifdef UART_C1_EN
static util_ringbuf_t uart1_txBuf;
static util_ringbuf_t uart1_rxBuf;
#endif
#ifdef UART_C2_EN
static util_ringbuf_t uart2_txBuf;
static util_ringbuf_t uart2_rxBuf;
#endif

/* Private function prototypes -----------------------------------------------*/
inline void txISRen(USART_TypeDef *uart);
inline void txISRdis(USART_TypeDef *uart);

/* Public functions ----------------------------------------------------------*/
int8_t uart_init(
		uart_channel_t channel,
		uint32_t baudrate,
		uint8_t *rxBuf,
		uint16_t rxBufSize,
		uint8_t *txBuf,
		uint16_t txBufSize)
{
	// prepare configuration variables
	util_ringbuf_t *rxRing;
	util_ringbuf_t *txRing;
	USART_TypeDef *dev;
	uint32_t devClkbus;
	uint32_t devClk;
	IRQn_Type devIrq;
	uint32_t txClk;
	GPIO_TypeDef *txPort;
	uint16_t txPin;
	uint8_t txAf;
	uint16_t txAfPin;
	uint32_t rxClk;
	GPIO_TypeDef *rxPort;
	uint16_t rxPin;
	uint8_t rxAf;
	uint16_t rxAfPin;

	switch (channel) {
#ifdef UART_C1_EN
	case UART_C1:
		rxRing = &uart1_rxBuf;
		txRing = &uart1_txBuf;
		dev = UART1_DEV;
		devClkbus = UART1_DEV_CLKBUS;
		devClk = UART1_DEV_CLK;
		devIrq = UART1_IRQ;
		txClk = UART1_TX_CLK;
		txPort = UART1_TX_PORT;
		txPin = UART1_TX_PIN;
		txAf = UART1_TX_AF;
		txAfPin = UART1_TX_AF_PIN;
		rxClk = UART1_RX_CLK;
		rxPort = UART1_RX_PORT;
		rxPin = UART1_RX_PIN;
		rxAf = UART1_RX_AF;
		rxAfPin = UART1_RX_AF_PIN;
		break;
#endif
#ifdef UART_C2_EN
	case UART_C2:
		rxRing = &uart2_rxBuf;
		rxRing = &uart2_txBuf;
		dev = UART2_DEV;
		devClkbus = UART2_DEV_CLKBUS;
		devClk = UART2_DEV_CLK;
		devIrq = UART2_IRQ;
		txClk = UART2_TX_CLK;
		txPort = UART2_TX_PORT;
		txPin = UART2_TX_PIN;
		txAf = UART2_TX_AF;
		txAfPin = UART2_TX_AF_PIN;
		rxClk = UART2_RX_CLK;
		rxPort = UART2_RX_PORT;
		rxPin = UART2_RX_PIN;
		rxAf = UART2_RX_AF;
		rxAfPin = UART2_RX_AF_PIN;
		break;
#endif
	}

	// initialize send and receive buffers
	util_ringbuf_init(rxRing, rxBuf, rxBufSize);
	util_ringbuf_init(txRing, txBuf, txBufSize);

	// enable module clocks for GPIO and UART
	if (devClkbus == APB2) {
		RCC_APB2PeriphClockCmd(devClk, ENABLE);
	} else if (devClkbus == APB1) {
		RCC_APB1PeriphClockCmd(devClk, ENABLE);
	}
	RCC_AHBPeriphClockCmd(rxClk, ENABLE);
	RCC_AHBPeriphClockCmd(txClk, ENABLE);

	// configure pins
	GPIO_InitTypeDef gpio_init;
	gpio_init.GPIO_Mode = GPIO_Mode_AF;
	gpio_init.GPIO_OType = GPIO_OType_PP;
	gpio_init.GPIO_PuPd = GPIO_PuPd_NOPULL;
	gpio_init.GPIO_Speed = GPIO_Speed_50MHz;
	gpio_init.GPIO_Pin = rxPin;
	GPIO_Init(rxPort, &gpio_init);
	GPIO_PinAFConfig(rxPort, rxAfPin, rxAf);
	gpio_init.GPIO_Pin = txPin;
	GPIO_Init(txPort, &gpio_init);
	GPIO_PinAFConfig(txPort, txAfPin, txAf);

	// configure UART device
	USART_InitTypeDef uart_init;
	uart_init.USART_BaudRate = baudrate;
	uart_init.USART_WordLength = USART_WordLength_8b;
	uart_init.USART_Parity = USART_Parity_No;
	uart_init.USART_StopBits = USART_StopBits_1;
	uart_init.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	uart_init.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_Init(dev, &uart_init);

	// configure interrupts
	NVIC_InitTypeDef nvic_init;
	nvic_init.NVIC_IRQChannel = devIrq;
	nvic_init.NVIC_IRQChannelPriority = 1;
	nvic_init.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&nvic_init);

	// enable the UART receive interrupt
	USART_ITConfig(dev, USART_IT_RXNE, ENABLE);

	return UART_OK;
}

int8_t uart_write(uart_channel_t channel, uint8_t data)
{
	int8_t res = -1;
	switch (channel) {
#ifdef UART_C1_EN
	case UART_C1:
		res = util_ringbuf_write(&uart1_txBuf, data);
		txISRen(USART1);
		break;
#endif
#ifdef UART_C2_EN
	case UART_C2:
		res = util_ringbuf_write(&uart2_txBuf, data);
		txISRen(USART2);
		break;
#endif
	}
	return res;
}

int32_t uart_writes(uart_channel_t channel, uint8_t data[], uint16_t size)
{
	int32_t res = -1;
	switch (channel) {
#ifdef UART_C1_EN
	case UART_C1:
		res = util_ringbuf_writes(&uart1_txBuf, data, size);
		txISRen(USART1);
		break;
#endif
#ifdef UART_C2_EN
	case UART_C2:
		res = util_ringbuf_writes(&uart2_txBuf, data, size);
		txISRen(USART2);
		break;
#endif
	}
	return res;
}

int8_t uart_read(uart_channel_t channel, uint8_t *data)
{
	util_ringbuf_t *buf;
	switch (channel) {
#ifdef UART_C1_EN
	case UART_C1:
		buf = &uart1_rxBuf;
		break;
#endif
#ifdef UART_C2_EN
	case UART_C2:
		buf = &uart2_rxBuf;
		break;
#endif
	}
	return util_ringbuf_read(buf, data);
}

int32_t uart_reads(uart_channel_t channel, uint8_t data[], uint16_t maxSize)
{
	util_ringbuf_t *buf;
	switch (channel) {
#ifdef UART_C1_EN
	case UART_C1:
		buf = &uart1_rxBuf;
		break;
#endif
#ifdef UART_C2_EN
	case UART_C2:
		buf = &uart2_rxBuf;
		break;
#endif
	}
	return util_ringbuf_reads(buf, data, maxSize);
}

/* Private functions ---------------------------------------------------------*/
void txISRen(USART_TypeDef *uart)
{
	USART_ITConfig(uart, USART_IT_TXE, ENABLE);
}

void txISRdis(USART_TypeDef *uart)
{
	USART_ITConfig(USART1, USART_IT_TXE, DISABLE);
}


#ifdef UART_C1_EN
void USART1_IRQHandler(void)
{
	uint8_t data;
	if (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == SET) {			// byte ready to send
		if (uart1_txBuf.count == 0) {
			txISRdis(USART1);
		}
		util_ringbuf_read(&uart1_txBuf, &data);
		USART_SendData(USART1, (uint16_t)data);
	} else if (USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == SET) {	// UART ready for read
		data = (uint8_t)(USART_ReceiveData(USART1) & 0x00ff);
		util_ringbuf_write(&uart1_rxBuf, data);
	}
}
#endif

#ifdef UART_C2_EN
void USART2_IRQHandler(void)
{
	uint8_t data;
	if (USART_GetFlagStatus(USART2, USART_FLAG_TXE) == SET) {			// byte ready to send
		if (uart2_txBuf.count == 0) {
			txISRdis(USART2);
		}
		util_ringbuf_read(&uart2_txBuf, &data);
		USART_SendData(USART2, (uint16_t)data);
	} else if (USART_GetFlagStatus(USART2, USART_FLAG_RXNE) == SET) {	// UART ready for read
		data = (uint8_t)(USART_ReceiveData(USART2) & 0x00ff);
		util_ringbuf_write(&uart2_rxBuf, data);
	}
}
#endif

#endif
