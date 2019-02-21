#include "./systick/bsp_systick.h"

/*采用读标志位值计时（后续延时函数建议使用这条）*/

void SysTick_Delay_ms(uint32_t ms) //uint32_t ms为用户的定计时变量，单位为ms
{
	uint32_t i;
	
	SysTick_Config(72000);//720000表示使用ms计时，改为72表示使用us计时（少用）
	
	for(i=0;i<ms;i++)
	{
		while( !( SysTick->CTRL & (1<<16) ));
	}
	
	/*失能systick*/
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
}
