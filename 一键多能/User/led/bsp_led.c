#include "./led/bsp_led.h"

void LED_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	/*��ʼ��LED�˿�ʱ��*/
	RCC_APB2PeriphClockCmd(LED_GPIO_PORT_Clock,ENABLE);
	
	/*��ʼ��LED1����*/
	GPIO_InitStruct.GPIO_Pin = LED1_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_10MHz;
	
	/*��ʼ��LED1�˿�*/
	GPIO_Init(LED_GPIO_PORT, &GPIO_InitStruct);
	
	
	/*��ʼ��LED2����*/
	GPIO_InitStruct.GPIO_Pin = LED2_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_10MHz;
	
	/*��ʼ��LED2�˿�*/
	GPIO_Init(LED_GPIO_PORT, &GPIO_InitStruct);
	
}
