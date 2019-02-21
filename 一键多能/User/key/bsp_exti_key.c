#include "./key/bsp_exti_key.h"

static void NVIC_Config(void)
{
	NVIC_InitTypeDef NVIC_InitStruct;
	
	/*��һ���������ж����ȼ��ķ���*/
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	
	/*�ڶ���������NVIC��ʼ���ṹ��*/
	NVIC_InitStruct.NVIC_IRQChannel = KEY1_EXTI_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	
	/*������������NVIC��ʼ�����������úõĽṹ��д���Ĵ�����*/
	NVIC_Init(&NVIC_InitStruct);
}

void KEY_EXTI_Config(void)
{ 
  /************************************
   ��һ������ʼ��Ҫ���ӵ�EXTI��KEY_GPIO
  *************************************/ 	
	GPIO_InitTypeDef GPIO_InitStruct;
  EXTI_InitTypeDef EXTI_InitStruct;	
	
	NVIC_Config();
	
	/*��ʼ��KEY1�˿�ʱ��*/
	RCC_APB2PeriphClockCmd(KEY1_GPIO_PORT_Clock,ENABLE);
	/*��ʼ��KEY1����*/
	GPIO_InitStruct.GPIO_Pin = KEY1_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	/*��ʼ��KEY1�˿�*/
	GPIO_Init(KEY1_GPIO_PORT, &GPIO_InitStruct);
	
	/**********************
   �ڶ�������ʼ��EXTI����
   **********************/

	/*��ʼ�����ù��ܵ�AFIO����*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	/*��PAO���ӵ�EXTI��*/
	GPIO_EXTILineConfig(KEY1_EXTI_GPIO_PortSource,KEY1_EXTI_GPIO_PinSource);
	
	/*��ʼ��EXTI����ṹ��*/
	EXTI_InitStruct.EXTI_Line     = KEY1_EXTI_LINE;
	EXTI_InitStruct.EXTI_Mode     = EXTI_Mode_Interrupt;
	EXTI_InitStruct.EXTI_Trigger  = EXTI_Trigger_Rising_Falling;
	EXTI_InitStruct.EXTI_LineCmd  = ENABLE;
	
	/*����EXTI��ʼ����������EXTI��ʼ���ṹ��д��Ĵ�����*/
	EXTI_Init(&EXTI_InitStruct);
	
}


