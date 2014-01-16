
#include <stdint.h>


typedef struct {
    int size;
    int count;
    int head;
    int tail;
    unsigned char *data;
} ringbuf_t;


int8_t ringbuf_init(ringbuf_t *buf, uint8_t *mem, uint16_t size);

int8_t ringbuf_write(ringbuf_t *buf, uint8_t data);
int32_t ringbuf_writes(ringbuf_t *buf, uint8_t *data, uint16_t size);

int32_t ringbuf_write_string(ringbuf_t *buf, char *str);

int8_t ringbuf_read(ringbuf_t *buf, uint8_t *data);
int32_t ringbuf_reads(ringbuf_t *buf, uint8_t *data, uint16_t maxSize);

int32_t ringbuf_copy(ringbuf_t *src, ringbuf_t *dst, uint16_t size);