/*!
 * spi.h
 * 
 * \brief		DESCRIPTION
 *
 * \detailed	DETAILED
 *
 *	\author		Hauke Petersen
 *  \date 		Jul 31, 2013
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef SPI_H_
#define SPI_H_

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx.h"
#include "llib/util.h"

/* Exported types ------------------------------------------------------------*/
typedef enum {
	SPI_C1							/*!< SPI channel 1 */
} spi_channel_t;

typedef enum {
	SPI_MASTER,						/*!< configure the SPI to run in Master mode */
	SPI_SLAVE						/*!< configure the SPI to run in Slave mode */
} spi_mode_t;

typedef struct {
	spi_channel_t channel;			/*!< the SPI channel (mapped to the hardware SPI modules) */
	spi_mode_t mode;				/*!< operating mode, either Master or Slave */
	uint32_t flags;					/*!< special flags defining the SPI behavior */
	uint32_t frequency;				/*!< the SPI clock frequency in Hz */
	util_ringbuf_t send_buf;		/*!< the send buffer used by the SPI */
	util_ringbuf_t recceive_buf;	/*!< the receive buffer used by the SPI */
} spi_t;

typedef struct {
	spi_channel_t channel;			/*!< the SPI channel (mapped to the hardware SPI modules) */
	spi_mode_t mode;				/*!< operating mode, either Master or Slave */
	uint32_t frequency;				/*!< the SPI clock frequency in Hz */
	uint8_t *send_mem;				/*!< memory for the send buffer */
	uint16_t send_size;				/*!< size of the send buffer */
	uint8_t *receive_mem;			/*!< memory for the receive buffer */
	uint16_t receive_size;			/*!< size of the receive buffer */
} spi_init_t;



/* Exported constants --------------------------------------------------------*/

/* Exported macros -----------------------------------------------------------*/
/* Exported variables --------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
int8_t spi_init(spi_t *spi, spi_init_t *init_data);

int8_t spi_send(spi_t *spi, uint8_t address, uint8_t *data, uint8_t size);
//int8_t spi_read(

#endif /* SPI_H_ */
