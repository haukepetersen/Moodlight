
#include <stdlib.h>
#include <stdio.h>

#include "useruart.h"
#include "uart.h"
#include "ringbuf.h"
#include "pwm.h"


void tx_cb(void);
void rx_cb(uint8_t data);

uint8_t rx_bufmem[USERUART_RX_BUFSIZE];
uint8_t tx_bufmem[USERUART_TX_BUFSIZE];

ringbuf_t rx_buf;
ringbuf_t tx_buf;

uint8_t newline_count = 0;

void useruart_init(void)
{
    // setup ringbuffer
    ringbuf_init(&rx_buf, rx_bufmem, USERUART_RX_BUFSIZE);
    ringbuf_init(&tx_buf, tx_bufmem, USERUART_TX_BUFSIZE);
    // setup underlying uart
    uart_init(USERUART_UART, USERUART_BAUD, &rx_cb, &tx_cb);
}


void useruart_run(void)
{
    if (newline_count >= 3) {
        uint8_t rgb[3];
        char buf[4];
        uint8_t data;
        for (uint8_t a = 0; a < 3; a++) {
            uint8_t i = 0;
            do {
                ringbuf_read(&rx_buf, &data);
                if (data >= '0' && data <= '9') {
                    buf[i++] = data;
                }
            } while (data != '\n');
            buf[i] = '\0';
            rgb[a] = atoi(buf);
        }
        newline_count -= 3;

        pwm_set(rgb);

        char str[40];
        uint8_t i = 0;
        sprintf(str, "New color: R:%i, G:%i, B:%i\n", rgb[0], rgb[1], rgb[2]);
        do {
            ringbuf_write(&tx_buf, str[i++]);
        } while (str[i] != '\0');

        uart_tx_begin(USERUART_UART);
    }
}


void tx_cb(void)
{
    if (tx_buf.count > 0) {
        uint8_t data;
        ringbuf_read(&tx_buf, &data);
        uart_write(USERUART_UART, data);
    } else {
        uart_tx_end(USERUART_UART);
    }
}

void rx_cb(uint8_t data)
{
    if (data == '\n') {
        ++newline_count;
    }
    ringbuf_write(&rx_buf, data);
}