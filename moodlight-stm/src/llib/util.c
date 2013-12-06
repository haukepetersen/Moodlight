/*!
 * util.c
 *
 *  Created on: Jul 23, 2013
 *      Author: PETERSEN
 */


/* Includes ------------------------------------------------------------------*/
#include "util.h"


/* Private typedefs ----------------------------------------------------------*/
/* Private defines -----------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/

/* Public functions ----------------------------------------------------------*/
int8_t util_ringbuf_init(util_ringbuf_t *buf, uint8_t *mem, uint16_t size)
{
	if (buf == NULL) {
		return -1;
	}
	buf->size = size;
	buf->head = 0;
	buf->tail = 0;
	buf->count = 0;
	buf->data = mem;
	return 0;
}

int8_t util_ringbuf_write(util_ringbuf_t *buf, uint8_t data)
{
	if (buf == NULL) {
		return -1;
	} else if (buf->size > buf->count) {
		buf->data[buf->head] = data;
		++buf->count;
		++buf->head;
		buf->head = (buf->size > buf->head) ? buf->head : 0;
		return 1;
	} else {
		return 0;
	}
}

int32_t util_ringbuf_writes(util_ringbuf_t *buf, uint8_t *data, uint16_t size)
{
	if (buf == NULL) {
		return -1;
	}
	uint16_t i = 0;
	int8_t n = 1;
	while (n > 0 && i < size) {
		n = util_ringbuf_write(buf, data[i]);
	}
	return (i == 0 && n < 0) ? n : i;
}

int8_t util_ringbuf_read(util_ringbuf_t *buf, uint8_t *data)
{
	if (buf == NULL) {
		return -1;
	} else if (buf->count > 0) {
		*data = buf->data[buf->tail];
		--buf->count;
		++buf->tail;
		buf->tail = (buf->size > buf->tail) ? buf->tail : 0;
		return 1;
	} else {
		return 0;
	}
}


int32_t util_ringbuf_reads(util_ringbuf_t *buf, uint8_t *data,	uint16_t maxSize)
{
	if (buf == NULL) {
		return -1;
	}
	uint16_t i = 0;
	while (i < maxSize && i < buf->count) {
		util_ringbuf_read(buf, &data[i]);
	}
	return i;
}

/* Private functions ---------------------------------------------------------*/

