/*!
 * i2c.h
 *
 *  Created on: Jul 23, 2013
 *      Author: PETERSEN
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef I2C_H_
#define I2C_H_

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx.h"

/* Exported types ------------------------------------------------------------*/
typedef enum {
	I2C_MASTER,
	I2C_SLAVE
} i2c_mode_t;

typedef enum {
	I2C_0,
	I2C_1
} i2c_channel_t;

typedef struct {
	i2c_channel_t channel;
	i2c_mode_t mode;
	uint8_t address;			/*! I2C address, 0 when in master mode */
	uint32_t flags;
	uint32_t frequency;			/*! Frequency of the i2c interface in Hz */
} i2c_t;

/* Exported constants --------------------------------------------------------*/

/* Exported macros -----------------------------------------------------------*/

/* Exported variables --------------------------------------------------------*/

/* Exported functions ------------------------------------------------------- */
int8_t i2c_init(i2c_t *i2c, i2c_channel_t channel, i2c_mode_t mode, uint32_t frequency);

int8_t i2c_send(i2c_t *i2c, uint8_t *data, uint8_t size);

int8_t i2c_setAddress(i2c_t *i2c, uint8_t address);

#endif /* I2C_H_ */
