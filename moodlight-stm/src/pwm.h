/*!
 * pwm.h
 *
 *  Created on: Apr 15, 2013
 *      Author: PETERSEN
 */

#ifndef PWM_H_
#define PWM_H_

#include "stm32f0xx.h"
#include "color.h"

#define PWM_TIMER			TIM2
#define PWM_TIM_IRQ			TIM2_IRQn
#define PWM_TIM_CLK			RCC_APB1Periph_TIM2
#define PWM_TIM_PRESCALER	0								// 48-1 (one tick every 1/48us)
#define PWM_TIM_PERIOD		48000							// pwm period is 1ms

#define PWM_PORT			GPIOA
#define PWM_PORT_CLK 		RCC_AHBPeriph_GPIOA
#define PWM_PINS			GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3
#define PWM_PIN_SRC1		GPIO_PinSource1
#define PWM_PIN_SRC2		GPIO_PinSource2
#define PWM_PIN_SRC3		GPIO_PinSource3




void pwm_init();

void pwm_cmd(FunctionalState newState);

void pwm_set(uint16_t r, uint16_t g, uint16_t b);


#endif /* PWM_H_ */
