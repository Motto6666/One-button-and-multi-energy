#include "./systick/bsp_systick.h"

/*���ö���־λֵ��ʱ��������ʱ��������ʹ��������*/

void SysTick_Delay_ms(uint32_t ms) //uint32_t msΪ�û��Ķ���ʱ��������λΪms
{
	uint32_t i;
	
	SysTick_Config(72000);//720000��ʾʹ��ms��ʱ����Ϊ72��ʾʹ��us��ʱ�����ã�
	
	for(i=0;i<ms;i++)
	{
		while( !( SysTick->CTRL & (1<<16) ));
	}
	
	/*ʧ��systick*/
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
}
