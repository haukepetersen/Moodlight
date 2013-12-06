/*!
 * i2c.c
 *
 *  Created on: Jul 23, 2013
 *      Author: PETERSEN
 */

/* Includes ------------------------------------------------------------------*/
#include "i2c.h"
#include "stm32f0xx_rcc.h"


/* Private typedefs ----------------------------------------------------------*/
/* Private defines -----------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/

/* Public functions ----------------------------------------------------------*/
int8_t i2c_init(i2c_t *i2c, i2c_channel_t channel, i2c_mode_t mode, uint32_t frequency)
{
	// pin configuration
	GPIO_TypeDef datPort;
	GPIO_TypeDef clkPort;
	uint32_t datPin;
	uint32_t clkPin;
	// interrupt configuration
	uint8_t irqChannel;





	GPIO_InitTypeDef gpio_init;
	NVIC_InitTypeDef nvic_init;
	I2C_InitTypeDef i2c_init;

	uint32_t i2cPeriph = (i2c->channel == I2C_0) ? RCC_APB1Periph_I2C1 : RCC_APB1Periph_I2C2;

//	// enable system ressources
//	RCC_APB1PeriphClockCmd(i2cPeriph, ENABLE);
//	RCC_AHBPeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
//
//	gpio_init.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9;
//	gpio_init.GPIO_Mode = GPIO_Mode_AF_OD;
//	gpio_init.GPIO_Speed = GPIO_Speed_50MHz;
//	GPIO_Init(datPort, &gpio_init);
//
//	// setup the interrupt channel
//
//	nvic_init.NVIC_IRQChannel = I2C1_EV_IRQn;
//	nvic_init.NVIC_IRQChannelPreemptionPriority = 0;
//	nvic_init.NVIC_IRQChannelSubPriority = 0;
//	nvic_init.NVIC_IRQChannelCmd = ENABLE;
//	NVIC_Init(&nvic_init);


	return 0;
}

int8_t i2c_send(i2c_t *i2c, uint8_t *data, uint8_t size)
{

}

int8_t i2c_setAddress(i2c_t *i2c, uint8_t address)
{

}

/* Private functions ---------------------------------------------------------*/
