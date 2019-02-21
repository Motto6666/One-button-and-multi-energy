#include "stm32f10x.h"
#include "./led/bsp_led.h"
#include "./systick/bsp_systick.h"
#include "./key/bsp_exti_key.h"
#include "./basetime/bsp_basetime.h"

volatile uint32_t blink_time_change_mode = 1;//初始化闪烁间隔增/减标识符为1（0和1之间切换）
volatile uint32_t blink_time = 5000;//初始化LED灯闪烁时间间隔为5000ms
volatile uint32_t time = 0; // ms 计时变量
volatile uint32_t Press_and_release = 1; //按下松开标识符，1表示按下，0表示松开

int main(void)
{
	LED_GPIO_Config();//初始化LED_GPIO外设
	
	KEY_EXTI_Config();//初始化KEY_EXTI外设
	
	BASIC_TIM_Init();//初始化BASIC_TIM外设
	while(1)
	{
		LED1_OFF;
		SysTick_Delay_ms(blink_time);//系统延时
		
		LED1_ON;
		SysTick_Delay_ms(blink_time);//系统延时
	}
}
