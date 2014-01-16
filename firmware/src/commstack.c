
#include <stdio.h>
#include <string.h>

#include "commstack.h"
#include "uart.h"
#include "ringbuf.h"
#include "pwm.h"
#include "led.h"

#define BUFSIZE             (128U)


static void rx_cb(uint8_t data);
static void tx_cb(void);

static void cmd_rgb_set(void);



static uint8_t rx_mem[BUFSIZE];
static uint8_t tx_mem[BUFSIZE];

static ringbuf_t rx_buf;
static ringbuf_t tx_buf;

static uart_t device = 0;

static uint8_t state = 0;



void commstack_init(uart_t dev, uint32_t baudrate)
{
    device = dev;
    uart_init(dev, baudrate, &rx_cb, &tx_cb);
    ringbuf_init(&rx_buf, rx_mem, BUFSIZE);
    ringbuf_init(&tx_buf, tx_mem, BUFSIZE);
}

void cmd_rgb_set(void)
{
    uint8_t rgb[3];
    int16_t res = ringbuf_reads(&rx_buf, rgb, 3);

    pwm_set(rgb);

    char msg[35];
    sprintf(msg, "Color set to R%i G%i B%i\n", rgb[0], rgb[1], rgb[2]);
    ringbuf_write_string(&tx_buf, msg);
    uart_tx_begin(device);
}


void rx_cb(uint8_t data)
{
    switch (state) {
        case COMM_CMD_RGB_SET:
            ringbuf_write(&rx_buf, data);
            if (rx_buf.count == 3) {
                cmd_rgb_set();
                state = 0;
            }
        break;
        default:
            state = data;
        break;
    }
}

void tx_cb(void)
{
    if (tx_buf.count > 0) {
        uint8_t data;
        ringbuf_read(&tx_buf, &data);
        uart_write(device, data);
    } else {
        uart_tx_end(device);
    }
}

