#include "stm32f10x.h"
#include "./led/bsp_led.h"
#include "./systick/bsp_systick.h"
#include "./key/bsp_exti_key.h"
#include "./basetime/bsp_basetime.h"

volatile uint32_t blink_time_change_mode = 1;//��ʼ����˸�����/����ʶ��Ϊ1��0��1֮���л���
volatile uint32_t blink_time = 5000;//��ʼ��LED����˸ʱ����Ϊ5000ms
volatile uint32_t time = 0; // ms ��ʱ����
volatile uint32_t Press_and_release = 1; //�����ɿ���ʶ����1��ʾ���£�0��ʾ�ɿ�

int main(void)
{
	LED_GPIO_Config();//��ʼ��LED_GPIO����
	
	KEY_EXTI_Config();//��ʼ��KEY_EXTI����
	
	BASIC_TIM_Init();//��ʼ��BASIC_TIM����
	while(1)
	{
		LED1_OFF;
		SysTick_Delay_ms(blink_time);//ϵͳ��ʱ
		
		LED1_ON;
		SysTick_Delay_ms(blink_time);//ϵͳ��ʱ
	}
}
