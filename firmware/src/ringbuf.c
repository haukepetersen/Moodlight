#include <stdlib.h>
#include <string.h>

#include "ringbuf.h"

int8_t ringbuf_init(ringbuf_t *buf, uint8_t *mem, uint16_t size)
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

int8_t ringbuf_write(ringbuf_t *buf, uint8_t data)
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

int32_t ringbuf_writes(ringbuf_t *buf, uint8_t *data, uint16_t size)
{
    if (buf == NULL) {
        return -1;
    }
    uint16_t i = 0;
    int8_t n = 1;
    while (n > 0 && i < size) {
        n = ringbuf_write(buf, data[i]);
    }
    return (i == 0 && n < 0) ? n : i;
}

int32_t ringbuf_write_string(ringbuf_t *buf, char *str)
{
    int8_t n = 1;
    int32_t i = 0;
    while (str[i] != '\0' && n > 0) {
        n = ringbuf_write(buf, (uint8_t)str[i++]);
    }
    return i + n - 1;
}

int8_t ringbuf_read(ringbuf_t *buf, uint8_t *data)
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


int32_t ringbuf_reads(ringbuf_t *buf, uint8_t *data,  uint16_t maxSize)
{
    if (buf == NULL) {
        return -1;
    }
    uint16_t i = 0;
    while (i < maxSize && buf->count > 0) {
        ringbuf_read(buf, &data[i++]);
    }
    return i;
}

int32_t ringbuf_copy(ringbuf_t *src, ringbuf_t *dst, uint16_t size)
{
    uint8_t data;
    int32_t ret = 1;
    int32_t sum = 0;
    while (size > 0 && ret) {
        ringbuf_read(src, &data);
        ret = ringbuf_write(dst, data);
        sum += ret;
        --size;
    }
    return sum;
}
