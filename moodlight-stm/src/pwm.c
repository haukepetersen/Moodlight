
#include "pwm.h"

#define RED		0		/*!< Defines the red color component */
#define GREEN	1
#define BLUE	2



uint16_t pwm_value[3];

/*!
 * \brief Initialize the PWM module.
 *
 * This method initializes the time used for the PWM signal generation.
 */
void pwm_init()
{
	// initialize pwm values
	for (uint8_t i = 0; i < 3; i++) {
		pwm_value[i] = 0;
	}

	// initialization data structures
	GPIO_InitTypeDef gpio_init;
	TIM_TimeBaseInitTypeDef tim_init_timebase;
	TIM_OCInitTypeDef tim_init_oc;
	NVIC_InitTypeDef nvic_init;

	// enable GPIO and TIM2 clocks
	RCC_AHBPeriphClockCmd(PWM_PORT_CLK, ENABLE);
	RCC_APB1PeriphClockCmd(PWM_TIM_CLK, ENABLE);


	// setup GPIO port used by PWM
	gpio_init.GPIO_Pin = PWM_PINS;
	gpio_init.GPIO_Mode = GPIO_Mode_AF;
	gpio_init.GPIO_Speed = GPIO_Speed_50MHz;
	gpio_init.GPIO_OType = GPIO_OType_PP;
	gpio_init.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(PWM_PORT, &gpio_init);
	// set the correct alternate function for MOTOR_PINS
	GPIO_PinAFConfig(PWM_PORT, PWM_PIN_SRC1, GPIO_AF_2);
	GPIO_PinAFConfig(PWM_PORT, PWM_PIN_SRC2, GPIO_AF_2);
	GPIO_PinAFConfig(PWM_PORT, PWM_PIN_SRC3, GPIO_AF_2);

	// setup the timebase for MOTOR_TIMER
	tim_init_timebase.TIM_ClockDivision = TIM_CKD_DIV1;				// use full 48MHz for timer
	tim_init_timebase.TIM_Prescaler = PWM_TIM_PRESCALER;
	tim_init_timebase.TIM_Period = PWM_TIM_PERIOD;
	tim_init_timebase.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(PWM_TIMER, &tim_init_timebase);

	// setup the output compare units for MOTOR_TIMER
	tim_init_oc.TIM_OCMode = TIM_OCMode_PWM1;
	tim_init_oc.TIM_OutputState = TIM_OutputState_Enable;
	tim_init_oc.TIM_OutputNState = TIM_OutputNState_Disable;
	tim_init_oc.TIM_OCIdleState = TIM_OCIdleState_Reset;
	tim_init_oc.TIM_OCPolarity = TIM_OCPolarity_High;
	tim_init_oc.TIM_Pulse = 0;										// make sure duty cycle is 0% at startup
	// write setup for all 4 OC units
	TIM_OC2Init(PWM_TIMER, &tim_init_oc);
	TIM_OC3Init(PWM_TIMER, &tim_init_oc);
	TIM_OC4Init(PWM_TIMER, &tim_init_oc);

	// enable timer update interrupt
	TIM_ITConfig(PWM_TIMER, TIM_IT_Update, ENABLE);

	// setup the interrupt for the pwm timer
	nvic_init.NVIC_IRQChannel = PWM_TIM_IRQ;
	nvic_init.NVIC_IRQChannelCmd = DISABLE;
	nvic_init.NVIC_IRQChannelPriority = 1;
	NVIC_Init(&nvic_init);


}


void pwm_cmd(FunctionalState newState)
{
	TIM_Cmd(PWM_TIMER, newState);
	TIM_CtrlPWMOutputs(PWM_TIMER, newState);
	NVIC_EnableIRQ(PWM_TIM_IRQ);
}

/*!
 * \brief Set the three PWM values to match a given color.
 *
 * \param r 	The red component of the color value.
 * \param g		The green component of the color value.
 * \param b		The blue component of the color value.
 */
void pwm_set(uint16_t r, uint16_t g, uint16_t b)
{
	pwm_value[RED] = (r > PWM_TIM_PERIOD) ? PWM_TIM_PERIOD : r;
	pwm_value[GREEN] = (g > PWM_TIM_PERIOD) ? PWM_TIM_PERIOD : g;
	pwm_value[BLUE] = (b > PWM_TIM_PERIOD) ? PWM_TIM_PERIOD : b;
	NVIC_EnableIRQ(PWM_TIM_IRQ);
}


/**
 * Timer 2 IRQ Handler
 */
void TIM2_IRQHandler()
{

	if (TIM_GetFlagStatus(PWM_TIMER, TIM_IT_Update) == SET) {
		NVIC_DisableIRQ(PWM_TIM_IRQ);
		TIM_SetCompare2(PWM_TIMER, (uint32_t)pwm_value[RED]);
		TIM_SetCompare3(PWM_TIMER, (uint32_t)pwm_value[GREEN]);
		TIM_SetCompare4(PWM_TIMER, (uint32_t)pwm_value[BLUE]);
		TIM_ClearFlag(PWM_TIMER, TIM_IT_Update);
	}
}

