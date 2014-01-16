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
 * @file        spi.c
 * @brief       Low-level SPI driver implementation
 *
 * @author      Hauke Petersen <mail@haukepetersen.de>
 * 
 * @}
 */

#include "spi.h"
#include "periph_config.h"

spi_state_t state[SPI_NUMOF];


void spi_init(spi_t dev,
             spi_mode_t mode,
             spi_clock_t clock,
             spi_polarity_t polarity,
             spi_phase_t phase,
             void (*rx_cb)(uint8_t data),
             void (*tx_cb)(void))
{
    state[dev].rx_cb = rx_cb;
    state[dev].tx_cb = tx_cb;


}