/**
 * comm.h
 *
 * This file defines the common communication protocol between the Fuckup LLCU and HLCU.
 *
 *  Created on: Mar 19, 2013
 *      Author: PETERSEN
 */

#ifndef COMM_H_
#define COMM_H_

#include "stm32f0xx.h"


#define COMM_UNIT			USART1
#define COMM_UNIT_IRQ		USART1_IRQn
#define COMM_UNIT_CLK		RCC_APB2Periph_USART1
#define COMM_BAUDRATE		115200			// set baudrate to 115200 bit/sec

#define COMM_PORT			GPIOB
#define COMM_PORT_CLK		RCC_AHBPeriph_GPIOB
#define COMM_PINS			GPIO_Pin_6 | GPIO_Pin_7
#define COMM_PIN_SRC1		GPIO_PinSource6
#define COMM_PIN_SRC2		GPIO_PinSource7
#define COMM_PIN_AF			GPIO_AF_0






typedef enum {
	COMM_Rx,
	COMM_Tx
} comm_module_t;



void comm_init();

void comm_cmd(FunctionalState newState);

void comm_send(uint8_t type, uint8_t *data, uint8_t size);



#endif /* COMM_H_ */
