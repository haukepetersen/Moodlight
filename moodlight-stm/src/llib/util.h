/*!
 * util.h
 *
 * \brief		Utility functions used in different driver modules.
 *
 *  \data		Jul 07, 2013
 *  \author 	Hauke Petersen
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef UTIL_H_
#define UTIL_H_

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx.h"

/* Exported types ------------------------------------------------------------*/
typedef struct {
	int size;
	int count;
	int head;
	int tail;
	unsigned char *data;
} util_ringbuf_t;

/* Exported constants --------------------------------------------------------*/
#define NULL		0

/* Exported macros -----------------------------------------------------------*/

/* Exported variables --------------------------------------------------------*/

/* Exported functions ------------------------------------------------------- */
int8_t util_ringbuf_init(util_ringbuf_t *buf, uint8_t *mem, uint16_t size);

int8_t util_ringbuf_write(util_ringbuf_t *buf, uint8_t data);
int32_t util_ringbuf_writes(util_ringbuf_t *buf, uint8_t *data, uint16_t size);

int8_t util_ringbuf_read(util_ringbuf_t *buf, uint8_t *data);
int32_t util_ringbuf_reads(util_ringbuf_t *buf, uint8_t *data, uint16_t maxSize);


#endif /* UTIL_H_ */
