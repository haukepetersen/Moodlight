/*!
 * uart.h
 *
 *  Created on: Jul 23, 2013
 *      Author: PETERSEN
 */

#ifndef UART_H_
#define UART_H_

typedef struct {
	uint32_t port;

	void(*done_sending_callback)();
	void(*received_callback)(uint8_t*, uint8_t);
} uart_t;


int uart_init(uart_t *port, int portnum);

int uart_receive(uart_t *port, char *buf, int max_size);
int uart_send(uart_t *port, char *data, int length);


#endif /* UART_H_ */
