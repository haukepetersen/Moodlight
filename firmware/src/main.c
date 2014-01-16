
#include <stdio.h>
#include <stdint.h>

#include "stm32f0xx.h"
#include "stm32f0xx_rcc.h"
#include "stm32f0xx_gpio.h"

#include "commstack.h"
#include "led.h"
#include "pwm.h"

#define PUSH_LIMIT          (30U)

// #define COMM_DEV            PERIPH_UART1
// #define COMM_BAUDRATE       (115200U)
#define COMM_DEV            UART_1
#define COMM_BAUDRATE       (9600U)

enum {
    STATE_R = 0,
    STATE_G,
    STATE_B,
    STATE_RG,
    STATE_GB,
    STATE_BR,
    STATE_SLIDE,
    STATE_END,
};


uint32_t state = 0;
uint32_t pushed = 0;

// uint16_t sliding_color[3] = {0, 255, 255};

int main(void);
void button_init(void);

void button_init(void)
{
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);

    GPIO_InitTypeDef gpio;
    gpio.GPIO_Mode = GPIO_Mode_IN;
    gpio.GPIO_Pin = GPIO_Pin_0;
    GPIO_Init(GPIOA, &gpio);
}

// void SysTick_Handler(void)
// {
//     if (state == STATE_SLIDE) {
//         sliding_color[0] = (++sliding_color[0] > 360) ? 0 : sliding_color[0];
//         uint8_t rgb[3];
//         color_hsv2rgb(sliding_color, rgb);
//         pwm_set(rgb);
//     }
// }

int main(void) 
{
    // uint8_t rgb[3];

    led_init();
    button_init();

    commstack_init(COMM_DEV, COMM_BAUDRATE);


    // uartbridge_send1("Hello UART 1\n", 13);
    // uartbridge_send2("Hello UART 2\n", 13);

    pwm_init();
    // SysTick_Config(48000 * 40);             // set systick interrupt to be triggered every 40ms        
    // SystemCoreClockUpdate();


    while (1) {

        // while (USART_GetFlagStatus(UART_2_DEV, USART_FLAG_TXE) == RESET);
        // USART_SendData(UART_2_DEV, 'X');

        if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0)) {
            led_set();
            ++pushed;
        } else {
            pushed = 0;
            led_clear();
        }

        if (pushed >= PUSH_LIMIT) {
            pushed = 0;
            state = ((state + 1) == STATE_END) ? 0 : state + 1;
            led_blink();
        }

        // switch (state) {
        //     case STATE_R:
        //         rgb[0] = 150; 
        //         rgb[1] = 0;
        //         rgb[2] = 0;
        //         pwm_set(rgb);
        //     break;
        //     case STATE_G:
        //         rgb[0] = 0;
        //         rgb[1] = 155;
        //         rgb[2] = 0;
        //         pwm_set(rgb);
        //     break;
        //     case STATE_B:
        //         rgb[0] = 0;
        //         rgb[1] = 0;
        //         rgb[2] = 155;
        //         pwm_set(rgb);
        //     break;
        //     case STATE_RG:
        //         rgb[0] = 155;
        //         rgb[1] = 155;
        //         rgb[2] = 0;
        //         pwm_set(rgb);
        //     break;
        //     case STATE_GB:
        //         rgb[0] = 0;
        //         rgb[1] = 155;
        //         rgb[2] = 155;
        //         pwm_set(rgb);
        //     break;
        //     case STATE_BR:
        //         rgb[0] = 155;
        //         rgb[1] = 0;
        //         rgb[2] = 155;
        //         pwm_set(rgb);
        //     break;
        //     case STATE_SLIDE:
                
        //     break;
        //     default:
        //         rgb[0] = 0;
        //         rgb[1] = 0;
        //         rgb[2] = 0;
        //         pwm_set(rgb);
        //     break;
        // }
    
    }
    return 0;
}
