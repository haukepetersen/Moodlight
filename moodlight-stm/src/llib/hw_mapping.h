/*!
 * hw_mapping.h
 * 
 * \brief		DESCRIPTION
 *
 * \detailed	This file describes the mapping of function units to port pins.
 *
 * Port A - 02  : UART 2 transmit
 * Port A - 03  : UART 2 transmit
 *
 * Port A - 09	: UART 1 transmit
 * Port A - 10  : UART 1 receive
 *
 *	\author		petersen
 *  \date 		Aug 1, 2013
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef HW_MAPPING_H_
#define HW_MAPPING_H_

#include "stm32f0xx.h"
#include "config.h"

/* General STM32 specific definitions ----------------------------------------*/
#define AHB			0
#define APB1		1
#define APB2		2


/* PWM -----------------------------------------------------------------------*/
#ifdef MODULE_PWM_EN
// PWM 1
#ifdef PWM_C1_EN
#define PWM1_TIM			TIM1
#define PWM_PIN		PA8 - PA11, AF 2

#endif
// PWM 2 ...

#define PWM5_TIM			TIM2
#define PWM_PIN		PA0 - PA4, AF2
// default configuration data
#define PWM_MAX_PRESCALE	0xffff
#endif

/* UART ----------------------------------------------------------------------*/
#ifdef MODULE_UART_EN
// UART 1
#ifdef UART_C1_EN
#define UART1_DEV			USART1
#define UART1_DEV_CLKBUS	APB2
#define UART1_DEV_CLK		RCC_APB2Periph_USART1
#define UART1_IRQ			USART1_IRQn
#define UART1_TX_CLKBUS		AHB
#define UART1_TX_CLK		RCC_AHBPeriph_GPIOA
#define UART1_TX_PORT		GPIOA
#define UART1_TX_PIN		GPIO_Pin_9
#define UART1_TX_AF			GPIO_AF_1
#define UART1_TX_AF_PIN		GPIO_PinSource9
#define UART1_RX_CLKBUS		AHB
#define UART1_RX_CLK		RCC_AHBPeriph_GPIOA
#define UART1_RX_PORT		GPIOA
#define UART1_RX_PIN		GPIO_Pin_10
#define UART1_RX_AF			GPIO_AF_1
#define UART1_RX_AF_PIN		GPIO_PinSource10
#endif
// UART 2
#ifdef UART_C2_EN
#define UART2_DEV			USART2
#define UART2_DEV_CLKBUS	APB1
#define UART2_DEV_CLK		RCC_APB1Periph_USART2
#define UART2_IRQ			USART2_IRQn
#define UART1_TX_CLKBUS		AHB
#define UART2_TX_CLK		RCC_AHBPeriph_GPIOA
#define UART2_TX_PORT		GPIOA
#define UART2_TX_PIN		GPIO_Pin_2
#define UART2_TX_AF			GPIO_AF_1
#define UART2_TX_AF_PIN		GPIO_PinSource2
#define UART2_RX_CLKBUS		AHB
#define UART2_RX_CLK		RCC_AHBPeriph_GPIOA
#define UART2_RX_PORT		GPIOA
#define UART2_RX_PIN		GPIO_Pin_3
#define UART2_RX_AF			GPIO_AF_1
#define UART2_RX_AF_PIN		GPIO_PinSource3
#endif
// default configuration data
#define UART_WORDLENGTH		USART_WordLength_8b
#define UART_PARITY			USART_Parity_No
#define UART_StopBits		USART_StopBits_1
#define UART_HW_FLOW_CTRL	USART_HardwareFlowControl_None
#define UART_DEFAULT_BAUD	115200
#endif


#endif /* HW_MAPPING_H_ */
