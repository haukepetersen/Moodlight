/*!
 * pwm.h
 * 
 * \brief		DESCRIPTION
 *
 * \detailed	DETAILED
 *
 *	\author		petersen
 *  \date 		Aug 2, 2013
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef PWM_H_
#define PWM_H_

/* Includes ------------------------------------------------------------------*/
#include "config.h"

/* Module enabler ------------------------------------------------------------*/
#ifdef MODULE_PWM_EN

/* Exported types ------------------------------------------------------------*/
typedef enum {
#ifdef PWM_C1_EN
	PWM_C1,
#endif
#ifdef PWM_C2_EN
	PWM_C2,
#endif
#ifdef PWM_C3_EN
	PWM_C3,
#endif
#ifdef PWM_C4_EN
	PWM_C4,
#endif
#ifdef PWM_C5_EN
	PWM_C5,
#endif
#ifdef PWM_C6_EN
	PWM_C6,
#endif
#ifdef PWM_C7_EN
	PWM_C7,
#endif
#ifdef PWM_C8_EN
	PWM_C8,
#endif
} pwm_channel_t;


/* Exported constants --------------------------------------------------------*/
#define PWM_OK		0
#define PWM_ERROR	-1

/* Exported macros -----------------------------------------------------------*/
/* Exported variables --------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
/*!
 * \brief		Initialize the given PWM channel
 *
 *
 * \param [in]	channel		PWM channel to initialize
 * \param [in]	frequency	frequency of the PWM in Hz
 * \param [in] 	resolution	Granularity of the PWM, the duty-cycle can be between 0 and resolution
 * \return		Returns PWM_OK when initialized correctly, PWM_ERROR otherwise
 */
//int8_t pwm_init(pwm_channel_t channel, uint32_t frequency, uint32_t resolution);
//
//int8_t pwm_start(pwm_channel_t channel);
//
//int8_t pwm_stop(pwm_channel_t channel);
//
//int8_t pwm_set(pwm_channel_t, float32_t dutyCycle);

#endif /* PWM_MODULE_EN */
#endif /* PWM_H_ */
