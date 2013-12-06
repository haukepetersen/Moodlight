/*!
 * \file 		uart.h
 * \brief		High-level UART driver Library for the STM32F0
 *
 * This file contains a high-level UART driver for the STM32F0 board. It can send
 * and receive data on the UART interfaces in a interrupt based manner while hiding
 * all buffering activity from the library user.
 *
 * The driver creates one channel for each available UART module on the target HW.
 *
 *	\author		Hauke Petersen
 *  \date 		2013-07-28
 *  \defgroup 	dri_uart	High-level UART driver
 *  @{
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef UART_H_
#define UART_H_

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include "config.h"

/* Module enabler ------------------------------------------------------------*/
#ifdef MODULE_UART_EN

/* Exported types ------------------------------------------------------------*/
/*!
 * @brief		Type describes available UART channels
 */
typedef enum {
#ifdef UART_C1_EN
	UART_C1,		/*! Channel 1 */
#endif
#ifdef UART_C2_EN
	UART_C2			/*! Channel 2 */
#endif
} uart_channel_t;


/* Exported constants --------------------------------------------------------*/
#define UART_ERROR	-1		/*! Return value in case of error */
#define UART_OK		0		/*! Return value when everything was OK */

/* Exported macros -----------------------------------------------------------*/
/* Exported variables --------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
/*!
 * \brief		Initialize an UART channel with given baudrate and buffers.
 *
 * The init function initializes a chosen UART channel with a given baudrate. Two
 * memory sections need to be defined that will be used as buffers for the received
 * and send data.
 *
 * \param [in] 	channel		The channel to initialize
 * \param [in]	baudrate	Baudrate to set the channel to, default is 115200
 * \param [in] 	rxBuf		Memory section for the receive buffer
 * \param [in] 	rxBufSize	Size of the receive buffer in byte
 * \param [in]	txBuf		Memory section for the send buffer
 * \param [in] 	txBufSize	Size of the send buffer in byte
 * \return 		UART_OK when initialized properly, UART_ERROR otherwise
 */
int8_t uart_init(
		uart_channel_t channel,
		uint32_t baudrate,
		uint8_t *rxBuf,
		uint16_t rxBufSize,
		uint8_t *txBuf,
		uint16_t txBufSize
		);

/*!
 * \brief		Register a callback function that is called when new data is received
 *
 * The UART driver gives the possibility to register a callback function that is called
 * when new data is received. The callback is executed in the ISR context and needs
 * therefore to be as short as possible.
 *
 * \param [in]	channel		Channel to hook into
 * \param [in] 	recCallback	Callback function that is called on new data
 * \return 		UART_OK when function was successfully registered, UART_ERROR otherwise
 */
int8_t uart_regReceiveCallback(uart_channel_t channel, void(*recCallback)(void));

/*!
 * \brief		Write a byte to the given UART channel
 *
 * Write one byte on the given UART channel. In case the send buffer is full the byte
 * will be dropped and 0 is returned.
 *
 * \param [in]	channel		Channel to send the data on
 * \param [in] 	data		Data to send
 * \return		Number of bytes send, 0 if nothing is send and UART_ERROR on error
 */
int8_t uart_write(uart_channel_t channel, uint8_t data);

/*!
 * \brief		Write a number of bytes to the given UART channel
 *
 * Write a number of bytes in the UART channel send buffer. The buffer contents are
 * then step by step send out on the given UART channel. The function will write as
 * many bytes as possible to the send buffer and will drop any not-fitting data.
 *
 * \param [in] 	channel		Channel to send the data on
 * \param [in]	data		Memory section containing the data to send
 * \param [in]	size		Number of bytes to send
 * \return		Number of bytes that were send, UART_ERROR on error
 */
int32_t uart_writes(uart_channel_t channel, uint8_t data[], uint16_t size);

/*!
 * \brief		Read one byte from the given UART channel
 *
 * Read a single byte from the UART channel's receive buffer. The method returns zero
 * for the case that no new data is available.
 *
 * \param [in]	channel		Channel to read data from
 * \param [out]	data		Data byte will be written to this address
 * \return 		1 if a byte was read, 0 if no data was available, UART_ERROR on error
 */
int8_t uart_read(uart_channel_t channel, uint8_t *data);

/*!
 * \brief		Read a number of bytes from the given UART channel
 *
 * Read all available data from the given UART channel. The number of bytes that are
 * read are only limited by the available data and the maxSize parameter. If no data
 * is available, the function returns 0.
 *
 * \param [in] 	channel		Channel to read from
 * \param [out]	data		Buffer to write the data into
 * \param [in]	maxSize		The maximum number of bytes to read from the UART channel
 * \return 		Number of bytes read, 0 if no data was available, UART_ERROR on error
 */
int32_t uart_reads(uart_channel_t channel, uint8_t data[], uint16_t maxSize);

/*!
 * @}
 */
#endif /* UART_MODULE_EN */
#endif /* UART_H_ */
