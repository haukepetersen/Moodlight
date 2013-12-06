/*!
 * \brief
 *
 * \description
 *
 *  \date 		23.07.2013
 *  \author		Hauke Petersen (mail@haukepetersen.de)
 */

#ifndef TIMER_H_
#define TIMER_H_


#define TIMER_ERR_INVALID_FREQ		-1
#define TIMER_ERR_INVALID_NUM		-2


#define TIMER_AUTORELOAD		0x00000001
#define TIMER_CONTINUOUS		0x00000002

typedef struct {
	uint32_t period;
	uint32_t flags;
	void (*overflow_callback)(void);
	void (*reload_callback)(void);
} timer_t;





int32_t timer_init(timer_t *timer, uint8_t timer_num, int32_t period);


/*!
 * \brief		Set the timer frequency in ticks per second.
 *
 * \param timer			Pointer to the affected timer instance
 * \param frequency		The time between two timer ticks
 * \return 				The time between two timer ticks that was actually set, 0 if a fault occurred
 * 						Warning: the actual period may differ from the desired value!
 */
int32_t timer_set_freq(timer_t *timer, int32_t period);


uint8_t timer_set_reload_value(timer_t *timer, uint32_t relaod_value);




#endif /* TIMER_H_ */
