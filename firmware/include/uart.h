/*
 * Copyright (C) 2014 Hauke Petersen <mail@haukepetersen.de>
 *
 * This file is subject to the terms and conditions of the GPLv2 License. 
 * See the file LICENSE in the top level directory for more details.
 */

/**
 * @file    uart.h
 * 
 * @author  Hauke Petersen <mail@haukepetersen.de>
 */

#ifndef __UART_H
#define __UART_H

#include <stdint.h>

typedef enum {
    UART_0 = 0,
    UART_1 = 1
} uart_t;

void uart_init(uart_t uart,
               uint32_t baudrate,
               void (*rx_cb)(uint8_t),
               void (*tx_cb)(void));

void uart_tx_begin(uart_t uart);
void uart_tx_end(uart_t uart);

int8_t uart_write(uart_t uart, uint8_t data);


#endif /* __UART_H */