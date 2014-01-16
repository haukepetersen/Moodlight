/*
 * Copyright (C) 2014 Hauke Petersen <mail@haukepetersen.de>
 *
 * This file is subject to the terms and conditions of the GPLv2 License. 
 * See the file LICENSE in the top level directory for more details.
 */

/**
 * @ingroup     periph
 * @{
 * 
 * @file        gpio.h
 * @brief       Low-level GPIO driver interface definition
 *
 * @author      Hauke Petersen <mail@haukepetersen.de>
 */

#ifndef __GPIO_H
#define __GPIO_H

#include "periph_config.h"

#ifdef GPIO_NUMOF
typedef enum {
#ifdef GPIO_0_EN
    GPIO_0 = 0,
#endif
#ifdef GPIO_1_EN
    GPIO_1,
#endif
#ifdef GPIO_2_EN
    GPIO_2,
#endif
#ifdef GPIO_3_EN
    GPIO_3,
#endif
#ifdef GPIO_4_EN
    GPIO_4,
#endif
#ifdef GPIO_5_EN
    GPIO_5,
#endif
#ifdef GPIO_6_EN
    GPIO_6,
#endif
#ifdef GPIO_7_EN
    GPIO_7,
#endif
#ifdef GPIO_8_EN
    GPIO_8,
#endif
#ifdef GPIO_9_EN
    GPIO_9,
#endif
#ifdef GPIO_10_EN
    GPIO_10,
#endif
#ifdef GPIO_11_EN
    GPIO_11,
#endif
#ifdef GPIO_12_EN
    GPIO_12,
#endif
#ifdef GPIO_13_EN
    GPIO_13,
#endif
#ifdef GPIO_14_EN
    GPIO_14,
#endif
#ifdef GPIO_15_EN
    GPIO_15
#endif
} gpio_t;
#endif

typedef enum {
    GPIO_PP_PULLDOWN,
    GPIO_PP_PULLUP,
    GPIO_PP_NOPULL
} gpio_pp_t;

typedef enum {
    GPIO_FLANK_FALLING,
    GPIO_FLANK_RISING,
    GPIO_FLANK_BOTH
} gpio_flank_t;

void gpio_init_out(gpio_t dev, gpio_pp_t pushpull);
void gpio_init_in(gpio_t dev, gpio_pp_t pushpull);
void gpio_init_int(gpio_t dev, gpio_pp_t pushpull, gpio_flank_t flank, void (*cb)(void));

int gpio_read(gpio_t dev);

void gpio_set(gpio_t dev);
void gpio_clear(gpio_t dev);
void gpio_toggle(gpio_t dev);
void gpio_write(gpio_t dev, int value);

void gpio_int_enable(gpio_t dev);
void gpio_int_disable(gpio_t dev);


#endif /* __GPIO_H */
/** @} */