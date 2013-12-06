/*!
 * \brief
 *
 * \description
 *
 *  \date 		23.07.2013
 *  \author 	Hauke Petersen (mail@haukepetersen.de)
 */

#ifndef PWM_H_
#define PWM_H_

#include "timer.h"

#define PWM_LEFT		0x00000000
#define PWM_RIGHT		0x00000001
#define PWM_CENTER		0x00000002
#define PWM_FASTSET		0x00000004


typedef struct {
	timer_t timer;
	uint32_t period;
	uint32_t duty_cycle;
	uint32_t flags;
	void (*center_callback)();
	void (*reload_callback)();
} pwm_t;



int8_t pwm_init(pwm_t *pwm, timer_t *timer, uint32_t period, uint32_t flags);

int8_t pwm_start(pwm_t *pwm);

int8_t pwm_stop(pwm_t *pwm);

/*!
 * \brief
 *
 * \description
 *
 * \param pwm			Pointer to the PWM instance that should be set
 * \param duty_cycle	The duty cycle to set: 10000: 100%, 0: 0%
 * \return				0 if everything is ok, -1 on error
 */
int8_t pwm_set(pwm_t *pwm, uint32_t duty_cylcle);

int8_t pwm_set_period(pwm_t *pwm, uint32_t period);

int8_t pwm_set_center_callback(pwm_t *pwm, void (*center)());

int8_t pwm_set_reload_callback(pwm_t *pwm, void (*reload)());


void pwm_callback(void);


#endif /* PWM_H_ */
