/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
 * Copyright (C) 2011 Damjan Marion <damjan.marion@gmail.com>
 * Copyright (C) 2011 Mark Panajotovic <marko@electrontube.org>
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <libopencm3/stm32/f0/rcc.h>
#include <libopencm3/stm32/f0/gpio.h>
#include <libopencm3/stm32/f0/usart.h>

void clock_setup(void);
void gpio_setup(void);
void uart_setup(void);

/* Set STM32 to 64 MHz. */
void clock_setup(void)
{
	rcc_clock_setup_in_hsi_out_8mhz();
}

void gpio_setup(void)
{
	/* Enable GPIOE clock. */
	rcc_periph_clock_enable(RCC_GPIOC);
	/* Set GPIO8-11 (in GPIO port E) to 'output push-pull'. */
	gpio_mode_setup(GPIOC, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO8 | GPIO9);
}

void uart_setup(void)
{
	/* setup clocks */
	rcc_periph_clock_enable(RCC_GPIOC);
	rcc_periph_clock_enable(RCC_USART1);
	/* setup pins */
	gpio_mode_setup(GPIOB, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO6 | GPIO7);
	gpio_set_af(GPIOB, GPIO_AF0, GPIO6 | GPIO7);
	/* setup UART */
	usart_set_baudrate(USART1, 115200);
	usart_set_databits(USART1, 8);
	usart_set_parity(USART1, USART_PARITY_NONE);
//	usart_set_stopbits(USART1, USART_STOPBITS_1);
	usart_set_flow_control(USART1, USART_FLOWCONTROL_NONE);
	usart_set_mode(USART1, USART_MODE_TX_RX);
	/* enable UART */
	usart_enable(USART1); 
}

int main(void)
{
	int i;

	clock_setup();
	gpio_setup();
//	uart_setup();

	/* Set two LEDs for wigwag effect when toggling. */
	gpio_set(GPIOC, GPIO8);
	gpio_clear(GPIOC, GPIO9);

	uint8_t up = 0;
	/* Blink the LEDs (PD8, PD9, PD10 and PD11) on the board. */
	while (1) {
		/* Toggle LEDs. */
		gpio_toggle(GPIOC, GPIO8 | GPIO9);
//		usart_send_blocking(USART1, '0' + up);
		up = (up == 10) ? 0 : ++up;
//		usart_send_blocking(USART1, '\n');
		for (i = 0; i < 1000000; i++) /* Wait a bit. */
			__asm__("nop");
	}

	return 0;
}
