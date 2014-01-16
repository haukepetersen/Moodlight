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
 * @file        spi.h
 * @brief       Low level SPI driver interface definition
 *
 * @author      Hauke Petersen <mail@haukepetersen.de>
 */

#ifndef __SPI_H
#define __SPI_H

#include <stdint.h>

/**
 * Definition of available SPI devices
 */
typedef enum {
    SPI_0 = 0,                  ///< SPI channel 1
    SPI_1 = 1,                  ///< SPI channel 2
} spi_t;

typedef enum {
    SPI_MODE_MASTER,            ///< Configure SPI device as master
    SPI_MODE_SLAVE              ///< Configure SPI device as slave
} spi_mode_t;

typedef enum {
    SPI_CLOCK_200KHZ,           ///< set SPI clock to 200KHz
    SPI_CLOCK_500KHZ,           ///< set SPI clock to 500KHz
    SPI_CLOCK_1MHZ,             ///< set SPI clock to 1MHz
    SPI_CLOCK_2MHZ,             ///< set SPI clock to 2MHz
    SPI_CLOCK_5MHZ              ///< set SPI clock to 5MHz
} spi_clock_t;

typedef enum {
    SPI_POLARITY_LOW = 0,       ///< Clk low when idle
    SPI_POLARITY_HIGH = 1       ///< Clk high when idkle
} spi_polarity_t;

typedef enum {
    SPI_PHASE_FIRST = 0,        ///< data capture on first edge
    SPI_PHASE_SECOND = 1        ///< data capture starts on second edge
} spi_phase_t;

typedef struct {
    void (*rx_cb)(uint8_t data);
    void (*tx_cb)(void);
} spi_state_t;


void spi_init(spi_t dev,
             spi_mode_t mode,
             spi_clock_t clock,
             spi_polarity_t polarity,
             spi_phase_t phase,
             void (*rx_cb)(uint8_t data),
             void (*tx_cb)(void));

void spi_tx_begin(void);
void spi_rx_begin(void);

int spi_write(spi_t dev, uint8_t data);


#endif /* __SPI_H */
/** @} */