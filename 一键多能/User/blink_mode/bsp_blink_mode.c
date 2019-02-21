#include "./blink_mode/bsp_blink_mode.h"
#include "./led/bsp_led.h"

extern volatile uint32_t time;
extern volatile uint32_t blink_time_change_mode; //LED灯闪烁模式，初始值为1
extern volatile uint32_t blink_time;//LED灯闪烁间隔时间

void blink_mode_change(void)
{
	
 if(time>=2000)//长按，切换blink_time_change_mode值
		{
			blink_time_change_mode = !(blink_time_change_mode);
			
			if(blink_time_change_mode == 0)
			{LED2_OFF;} //关闭LED2，表示切换到增加闪烁间隔时间模式0
			else
			{LED2_ON;}//打开LED2，表示切换到减少闪烁间隔时间模式1
		}
		else//短按，改变闪烁间隔
		{
			switch(blink_time_change_mode)//选择闪烁间隔增/减模式
			{
				case 0:
					if(blink_time >= 5000)
					{
						blink_time = 5000;//恢复到最初闪烁间隔时间5000ms
					}
					else
					{
						blink_time += 2000; //闪烁间隔时间增加2000ms
					}break;
				
				case 1:
					if(blink_time <= 1000)
					{
						blink_time = 5000;//恢复到最初闪烁间隔时间5000ms
					}
					else
					{
						blink_time -= 2000;//闪烁间隔时间减少2000ms
					}break;
				
				default:  break;
			}	
		}
}
