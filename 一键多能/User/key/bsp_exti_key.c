#include "./key/bsp_exti_key.h"

static void NVIC_Config(void)
{
	NVIC_InitTypeDef NVIC_InitStruct;
	
	/*第一步：配置中断优先级的分组*/
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	
	/*第二步：配置NVIC初始化结构体*/
	NVIC_InitStruct.NVIC_IRQChannel = KEY1_EXTI_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	
	/*第三步：调用NVIC初始化函数把配置好的结构体写到寄存器里*/
	NVIC_Init(&NVIC_InitStruct);
}

void KEY_EXTI_Config(void)
{ 
  /************************************
   第一步：初始化要连接到EXTI的KEY_GPIO
  *************************************/ 	
	GPIO_InitTypeDef GPIO_InitStruct;
  EXTI_InitTypeDef EXTI_InitStruct;	
	
	NVIC_Config();
	
	/*初始化KEY1端口时钟*/
	RCC_APB2PeriphClockCmd(KEY1_GPIO_PORT_Clock,ENABLE);
	/*初始化KEY1引脚*/
	GPIO_InitStruct.GPIO_Pin = KEY1_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	/*初始化KEY1端口*/
	GPIO_Init(KEY1_GPIO_PORT, &GPIO_InitStruct);
	
	/**********************
   第二步：初始化EXTI外设
   **********************/

	/*初始化复用功能的AFIO配置*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	/*将PAO连接到EXTI中*/
	GPIO_EXTILineConfig(KEY1_EXTI_GPIO_PortSource,KEY1_EXTI_GPIO_PinSource);
	
	/*初始化EXTI外设结构体*/
	EXTI_InitStruct.EXTI_Line     = KEY1_EXTI_LINE;
	EXTI_InitStruct.EXTI_Mode     = EXTI_Mode_Interrupt;
	EXTI_InitStruct.EXTI_Trigger  = EXTI_Trigger_Rising_Falling;
	EXTI_InitStruct.EXTI_LineCmd  = ENABLE;
	
	/*调用EXTI初始化函数，将EXTI初始化结构体写入寄存器里*/
	EXTI_Init(&EXTI_InitStruct);
	
}


