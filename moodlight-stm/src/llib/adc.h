/*!
 * adc.h
 *
 *  Created on: Jul 24, 2013
 *      Author: PETERSEN
 */

#ifndef ADC_H_
#define ADC_H_

typedef struct {
	uint8_t port;
	uint8_t pin;
	uint32_t sampling_rate;
	void (*data_ready_callback)(uint16_t);
} adc_t;



int8_t adc_init(adc_t *adc, uint8_t port, uint8_t pin, uint32_t sampling_rate, void (*data_ready_callback)(uint16_t));

int8_t adc_start(adc_t *adc);
int8_t adc_stop(adc_t *adc);

int8_t adc_single_shot(adc_t *adc);

uint16_t adc_blocking_conversion(adc_t *adc);


int32_t adc_set_sampling_rate(adc_t *adc, uint32_t sampling_rate);
int8_t adc_set_data_ready_callback(adc_t *adc, void (*data_ready_callback)(uint16_t));





#endif /* ADC_H_ */
