
#include "uartbridge.h"
#include "uart.h"
#include "ringbuf.h"

#define DEV1        UART_0
#define BAUD1       (115200U)

#define DEV2        UART_1
#define BAUD2       (9600U)

#define BUFSIZE     (256U)

uint8_t buf1[BUFSIZE];
uint8_t buf2[BUFSIZE];

ringbuf_t ring1;
ringbuf_t ring2;


void rx1(uint8_t data);
void tx1(void);

void rx2(uint8_t data);
void tx2(void);

void uartbridge_init(void)
{
    //init uart 1
    uart_init(DEV1, BAUD1, &rx1, &tx1);
    uart_init(DEV2, BAUD2, &rx2, &tx2);
    ringbuf_init(&ring1, buf1, BUFSIZE);
    ringbuf_init(&ring2, buf2, BUFSIZE);
}


void uartbridge_send1(char *data, uint16_t size)
{
    ringbuf_writes(&ring1, (uint8_t*)data, size);
    uart_tx_begin(DEV1);
}

void uartbridge_send2(char *data, uint16_t size)
{
    ringbuf_writes(&ring2, (uint8_t*)data, size);
    uart_tx_begin(DEV2);
}



void rx1(uint8_t data)
{
    ringbuf_write(&ring2, data);
    uart_tx_begin(DEV2);
}

void tx1(void)
{
    if (ring1.count > 0) {
        uint8_t data;
        ringbuf_read(&ring1, &data);
        uart_write(DEV1, data);
    } else {
        uart_tx_end(DEV1);
    }
}

void rx2(uint8_t data)
{
    ringbuf_write(&ring1, data);
    uart_tx_begin(DEV1);
}

void tx2(void)
{
    if (ring2.count > 0) {
        uint8_t data;
        ringbuf_read(&ring2, &data);
        uart_write(DEV2, data);
    } else {
        uart_tx_end(DEV2);
    }
}
