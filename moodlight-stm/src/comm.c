/*
 * comm.c
 *
 *  Created on: Mar 19, 2013
 *      Author: PETERSEN
 */

#include "comm.h"

#include "color.h"


/**
 * Define the message haeder structure.
 */
#define MSSG_MASK				0xc0
#define MSSG_HEAD				0xc0
#define MSSG_DATA				0x00

#define MSSG_TYPE_MASK			0x38
#define MSSG_SIZE_MASK			0x07




/**** Local variables **************************************************************************************/
enum {
	HEAD,
	DATA
} comm_state;

typedef struct {
	uint8_t type;
	uint8_t size;
	uint8_t count;
	uint8_t data[16];
} comm_mssg_t;

comm_mssg_t comm_incoming;


/**** Local function definitions ***************************************************************************/
void comm_receive(uint8_t data);
void comm_receive_head(uint8_t data);
void comm_receive_type(uint8_t data);
void comm_receive_data(uint8_t data);
void comm_process();
void comm_tx_int(FunctionalState state);


/**** Public functions *************************************************************************************/
void comm_init(void)
{
	// initialize send queue
//	sup_ringbuf_init(&comm_sendqueue, COMM_SENDQUEUE_SIZE);

	// config structs
	USART_InitTypeDef usart_init_struct;
	GPIO_InitTypeDef gpio_init_struct;
	NVIC_InitTypeDef nvic_init_struct;

	// enable USART1 and GPIO_A
	RCC_APB2PeriphClockCmd(COMM_UNIT_CLK, ENABLE);
	RCC_AHBPeriphClockCmd(COMM_PORT_CLK, ENABLE);

	// connect pins to USART1
	GPIO_PinAFConfig(COMM_PORT, COMM_PIN_SRC1, COMM_PIN_AF);
	GPIO_PinAFConfig(COMM_PORT, COMM_PIN_SRC2, COMM_PIN_AF);

	// set GPIO config options
	gpio_init_struct.GPIO_Pin = COMM_PINS;
	gpio_init_struct.GPIO_Mode = GPIO_Mode_AF;
	gpio_init_struct.GPIO_Speed = GPIO_Speed_50MHz;
	gpio_init_struct.GPIO_OType = GPIO_OType_PP;
	gpio_init_struct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	// write config to pins
	GPIO_Init(COMM_PORT, &gpio_init_struct);

	// set USART config options
	usart_init_struct.USART_BaudRate = COMM_BAUDRATE;
	usart_init_struct.USART_WordLength = USART_WordLength_8b;
	usart_init_struct.USART_Parity = USART_Parity_No;
	usart_init_struct.USART_StopBits = USART_StopBits_1;
	usart_init_struct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	usart_init_struct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	// write USART1 options
	USART_Init(COMM_UNIT, &usart_init_struct);

	// setup USART1 interrupt for Rx and Tx
	nvic_init_struct.NVIC_IRQChannel = COMM_UNIT_IRQ;
	nvic_init_struct.NVIC_IRQChannelPriority = 1;
	nvic_init_struct.NVIC_IRQChannelCmd = DISABLE;
	// write NVIC configuration
	NVIC_Init(&nvic_init_struct);

	// enable receive interrupt for COMM_UNIT
	USART_ITConfig(COMM_UNIT, USART_IT_RXNE, ENABLE);

}

void comm_cmd(FunctionalState newState)
{
	USART_Cmd(COMM_UNIT, newState);
	NVIC_EnableIRQ(COMM_UNIT_IRQ);
}

//void comm_send(uint8_t type, uint8_t *data, uint8_t size)
//{
//	uint8_t head = MSSG_START | ((size + 1) & 0x0f);
//	sup_ringbuf_write(&comm_sendqueue, &head, 1);
//	sup_ringbuf_write(&comm_sendqueue, &type, 1);
//	sup_ringbuf_write(&comm_sendqueue, data, size);
//	comm_tx_int(ENABLE);								// make sure tx interrupt is enabled
//}


/**** Private functions ************************************************************************************/
void comm_receive(uint8_t data)
{
	switch (comm_state) {
	case HEAD:
		comm_receive_head(data);
		break;
	case DATA:
		comm_receive_data(data);
		break;
	}
}

void comm_receive_head(uint8_t data)
{
	if ((data & MSSG_MASK) == MSSG_HEAD) {
		comm_incoming.type = (data & MSSG_TYPE_MASK) >> 3;
		comm_incoming.size = data & MSSG_SIZE_MASK;
		comm_incoming.count = 0;
		comm_state = DATA;
	}
}

void comm_receive_data(uint8_t data)
{
	if (data & MSSG_MASK != MSSG_DATA) {
		comm_state = HEAD;
	} else {
		comm_incoming.data[comm_incoming.count++] = data;
		if (comm_incoming.count == comm_incoming.size) {
			uint16_t r = ((comm_incoming.data[0] & 0x03) << 8) & comm_incoming.data[1];
			uint16_t g = ((comm_incoming.data[2] & 0x03) << 8) & comm_incoming.data[3];
			uint16_t b = ((comm_incoming.data[4] & 0x03) << 8) & comm_incoming.data[5];
			color_set(r, g, b);
			comm_state = HEAD;
		}
	}
}







void comm_tx_int(FunctionalState state)
{
	USART_ITConfig(USART1, USART_IT_TXE, state);
}

/**** Interrupt handlers ***********************************************************************************/
//void USART1_IRQHandler(void)
//{
//	if (USART_GetITStatus(USART1, USART_IT_RXNE) == SET) {		// RXNE is cleared by reading the RDR register
//		uint8_t tmp = (uint8_t)USART_ReceiveData(USART1);
//		comm_receive(tmp);
//	}
////	else if (USART_GetITStatus(USART1, USART_IT_TXE) == SET) {	// TXE is cleared by writing the TDR register
////		if (comm_sendqueue.count > 0) {
////			USART_SendData(USART1, (uint16_t)sup_ringbuf_get(&comm_sendqueue));
////		} else {
////			comm_tx_int(DISABLE);
////		}
////	}
//}
