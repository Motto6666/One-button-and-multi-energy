#ifndef __BSP_LED_H
#define __BSP_LED_H
#include "stm32f10x.h"

#define LED_GPIO_PORT_Clock    RCC_APB2Periph_GPIOC
#define LED_GPIO_PORT          GPIOC

#define LED1_PIN               GPIO_Pin_2
#define LED2_PIN               GPIO_Pin_3 	

#define LED1_ON                GPIO_ResetBits(LED_GPIO_PORT, LED1_PIN)
#define LED1_OFF               GPIO_SetBits(LED_GPIO_PORT, LED1_PIN)

#define LED2_ON                GPIO_ResetBits(LED_GPIO_PORT, LED2_PIN)
#define LED2_OFF               GPIO_SetBits(LED_GPIO_PORT, LED2_PIN)

void LED_GPIO_Config(void);

#endif /*__BSP_LED_H*/
