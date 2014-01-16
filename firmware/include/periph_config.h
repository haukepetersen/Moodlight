/*
 * Copyright (C) 2014 Hauke Petersen <mail@haukepetersen.de>
 *
 * This file is subject to the terms and conditions of the GPLv2 License. 
 * See the file LICENSE in the top level directory for more details.
 */

/**
 * @file    periph_config.h
 *
 * @author  Hauke Petersen <mail@haukepetersen.de>
 */

#ifndef __PERIPH_CONFIG_H
#define __PERIPH_CONFIG_H

/**
 * @brief GPIO configuration
 */
#define GPIO_NUMOF          16
#define GPIO_0_EN           1
#define GPIO_1_EN           1
#define GPIO_2_EN           1
#define GPIO_3_EN           1
#define GPIO_4_EN           1
#define GPIO_5_EN           1
#define GPIO_6_EN           1
#define GPIO_7_EN           1
#define GPIO_8_EN           1
#define GPIO_9_EN           1
#define GPIO_10_EN          1
#define GPIO_11_EN          1
#define GPIO_12_EN          1
#define GPIO_13_EN          1
#define GPIO_14_EN          1
#define GPIO_15_EN          1
#define GPIO_IRQ_PRIO       1
// GPIO channel 0 config
#define GPIO_0_PORT         GPIOC
#define GPIO_0_PIN          GPIO_Pin_9
#define GPIO_0_CLKEN()      RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE)
#define GPIO_0_LINE         EXTI_Line0
#define GPIO_0_IRQ          EXTI4_15_IRQn
#define GPIO_0_EXTI_MAP()   SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOC, EXTI_PinSource9)
// GPIO channel 1 config
#define GPIO_1_PORT         GPIOC
#define GPIO_1_PIN          GPIO_Pin_9
#define GPIO_1_CLKEN()      RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE)
#define GPIO_1_LINE         EXTI_Line0
#define GPIO_1_IRQ          EXTI4_15_IRQn
#define GPIO_1_EXTI_MAP()   SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOC, EXTI_PinSource9)
// GPIO channel 2 config
#define GPIO_2_PORT         GPIOA
#define GPIO_2_PIN          GPIO_Pin_0
#define GPIO_2_CLKEN()      RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE)
#define GPIO_2_LINE         EXTI_Line0
#define GPIO_2_IRQ          EXTI4_15_IRQn
#define GPIO_2_EXTI_MAP()   SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource0)
// GPIO channel 3 config
#define GPIO_3_PORT         GPIOA
#define GPIO_3_PIN          GPIO_Pin_0
#define GPIO_3_CLKEN()      RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE)
#define GPIO_3_LINE         EXTI_Line0
#define GPIO_3_IRQ          EXTI4_15_IRQn
#define GPIO_3_EXTI_MAP()   SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource0)
// GPIO channel 4 config
#define GPIO_4_PORT         GPIOA
#define GPIO_4_PIN          GPIO_Pin_0
#define GPIO_4_CLKEN()      RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE)
#define GPIO_4_LINE         EXTI_Line0
#define GPIO_4_IRQ          EXTI4_15_IRQn
#define GPIO_4_EXTI_MAP()   SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource0)
// GPIO channel 5 config
#define GPIO_5_PORT         GPIOA
#define GPIO_5_PIN          GPIO_Pin_0
#define GPIO_5_CLKEN()      RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE)
#define GPIO_5_LINE         EXTI_Line0
#define GPIO_5_IRQ          EXTI4_15_IRQn
#define GPIO_5_EXTI_MAP()   SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource0)
// GPIO channel 6 config
#define GPIO_6_PORT         GPIOA
#define GPIO_6_PIN          GPIO_Pin_0
#define GPIO_6_CLKEN()      RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE)
#define GPIO_6_LINE         EXTI_Line0
#define GPIO_6_IRQ          EXTI4_15_IRQn
#define GPIO_6_EXTI_MAP()   SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource0)
// GPIO channel 7 config
#define GPIO_7_PORT         GPIOA
#define GPIO_7_PIN          GPIO_Pin_0
#define GPIO_7_CLKEN()      RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE)
#define GPIO_7_LINE         EXTI_Line0
#define GPIO_7_IRQ          EXTI4_15_IRQn
#define GPIO_7_EXTI_MAP()   SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource0)
// GPIO channel 8 config
#define GPIO_8_PORT         GPIOA
#define GPIO_8_PIN          GPIO_Pin_0
#define GPIO_8_CLKEN()      RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE)
#define GPIO_8_LINE         EXTI_Line0
#define GPIO_8_IRQ          EXTI4_15_IRQn
#define GPIO_8_EXTI_MAP()   SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource0)
// GPIO channel 9 config
#define GPIO_9_PORT         GPIOA
#define GPIO_9_PIN          GPIO_Pin_0
#define GPIO_9_CLKEN()      RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE)
#define GPIO_9_LINE         EXTI_Line0
#define GPIO_9_IRQ          EXTI4_15_IRQn
#define GPIO_9_EXTI_MAP()   SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource0)
// GPIO channel 10 config
#define GPIO_10_PORT        GPIOA
#define GPIO_10_PIN         GPIO_Pin_0
#define GPIO_10_CLKEN()     RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE)
#define GPIO_10_LINE        EXTI_Line0
#define GPIO_10_IRQ         EXTI4_15_IRQn
#define GPIO_10_EXTI_MAP()  SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource0)
// GPIO channel 11 config
#define GPIO_11_PORT        GPIOA
#define GPIO_11_PIN         GPIO_Pin_0
#define GPIO_11_CLKEN()     RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE)
#define GPIO_11_LINE        EXTI_Line0
#define GPIO_11_IRQ         EXTI4_15_IRQn
#define GPIO_11_EXTI_MAP()  SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource0)
// GPIO channel 12 config
#define GPIO_12_PORT        GPIOA
#define GPIO_12_PIN         GPIO_Pin_0
#define GPIO_12_CLKEN()     RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE)
#define GPIO_12_LINE        EXTI_Line0
#define GPIO_12_IRQ         EXTI4_15_IRQn
#define GPIO_12_EXTI_MAP()  SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource0)
// GPIO channel 13 config
#define GPIO_13_PORT        GPIOA
#define GPIO_13_PIN         GPIO_Pin_0
#define GPIO_13_CLKEN()     RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE)
#define GPIO_13_LINE        EXTI_Line0
#define GPIO_13_IRQ         EXTI4_15_IRQn
#define GPIO_13_EXTI_MAP()  SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource0)
// GPIO channel 14 config
#define GPIO_14_PORT        GPIOA
#define GPIO_14_PIN         GPIO_Pin_0
#define GPIO_14_CLKEN()     RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE)
#define GPIO_14_LINE        EXTI_Line0
#define GPIO_14_IRQ         EXTI4_15_IRQn
#define GPIO_14_EXTI_MAP()  SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource0)
// GPIO channel 15 config
#define GPIO_15_PORT        GPIOA
#define GPIO_15_PIN         GPIO_Pin_0
#define GPIO_15_CLKEN()     RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE)
#define GPIO_15_LINE        EXTI_Line0
#define GPIO_15_IRQ         EXTI4_15_IRQn
#define GPIO_15_EXTI_MAP()  SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource0)


/**
 * @brief UART configuration
 */
#define UART_NUMOF          (2U)
#define UART_0_EN           1
#define UART_1_EN           1
#define UART_IRQ_PRIO       1

// UART 1 device config
#define UART_0_DEV          USART1
#define UART_0_CLKEN()      RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE)
#define UART_0_IRQ          USART1_IRQn
#define UART_0_IRQ_HANDLER  USART1_IRQHandler
// UART 1 RX pin config
#define UART_0_PORT         GPIOB
#define UART_0_PINS         (GPIO_Pin_6 | GPIO_Pin_7)
#define UART_0_PORT_CLKEN() RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE)
#define UART_0_RX_AFCFG()   (GPIO_PinAFConfig(UART_0_PORT, GPIO_PinSource6, GPIO_AF_0))
#define UART_0_TX_AFCFG()   (GPIO_PinAFConfig(UART_0_PORT, GPIO_PinSource7, GPIO_AF_0))

// UART 2 device config
#define UART_1_DEV          USART2
#define UART_1_CLKEN()      RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE)
#define UART_1_IRQ          USART2_IRQn
#define UART_1_IRQ_HANDLER  USART2_IRQHandler
// UART 1 RX pin config
#define UART_1_PORT         GPIOA
#define UART_1_PINS         (GPIO_Pin_2 | GPIO_Pin_3)
#define UART_1_PORT_CLKEN() RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE)
#define UART_1_RX_AFCFG()   GPIO_PinAFConfig(UART_1_PORT, GPIO_PinSource2, GPIO_AF_1)
#define UART_1_TX_AFCFG()   GPIO_PinAFConfig(UART_1_PORT, GPIO_PinSource3, GPIO_AF_1)

/**
 * @brief SPI configuration
 */
#define SPI_NUMOF           (2U)
#define SPI_0_EN            1
#define SPI_1_EN            1
#define SPI_IRQ_PRIO        1
// SPI 1 device config
#define SPI_0_DEV           SPI1
#define SPI_0_CLKEN()       RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE)
#define SPI_0_IRq           SPI1_IRQn
#define SPI_0_IRQ_HANDLER   SPI1_IRQHandler
// SPI 1 Pin config
#define SPI_0_PORT          GPIOA
#define SPI_0_PINS          (GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7)
#define SPI_0_PORT_CLKEN()  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE)
#define SPI_0_CLK_AFCFG()   GPIO_PinAFConfig(SPI_1_PORT, GPIO_PinSource5, GPIO_AF_0)
#define SPI_0_MOSI_AFCFG()  GPIO_PinAFConfig(SPI_1_PORT, GPIO_PinSource6, GPIO_AF_0)
#define SPI_0_MISO_AFCFG()  GPIO_PinAFConfig(SPI_1_PORT, GPIO_PinSource7, GPIO_AF_0)

// SPI 1 device config
#define SPI_1_DEV           SPI2
#define SPI_1_CLKEN()       RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI2, ENABLE)
#define SPI_1_IRq           SPI2_IRQn
#define SPI_1_IRQ_HANDLER   SPI2_IRQHandler
// SPI 1 Pin config
#define SPI_1_PORT          GPIOB
#define SPI_1_PINS          (GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15)
#define SPI_1_PORT_CLKEN()  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE)
#define SPI_1_CLK_AFCFG()   GPIO_PinAFConfig(SPI_1_PORT, GPIO_PinSource5, GPIO_AF_1)
#define SPI_1_MOSI_AFCFG()  GPIO_PinAFConfig(SPI_1_PORT, GPIO_PinSource6, GPIO_AF_1)
#define SPI_1_MISO_AFCFG()  GPIO_PinAFConfig(SPI_1_PORT, GPIO_PinSource7, GPIO_AF_1)


#endif /* __PERIPH_CONFIG_H */