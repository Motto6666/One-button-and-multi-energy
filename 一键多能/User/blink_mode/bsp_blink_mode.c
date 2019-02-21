#include "./blink_mode/bsp_blink_mode.h"
#include "./led/bsp_led.h"

extern volatile uint32_t time;
extern volatile uint32_t blink_time_change_mode; //LED����˸ģʽ����ʼֵΪ1
extern volatile uint32_t blink_time;//LED����˸���ʱ��

void blink_mode_change(void)
{
	
 if(time>=2000)//�������л�blink_time_change_modeֵ
		{
			blink_time_change_mode = !(blink_time_change_mode);
			
			if(blink_time_change_mode == 0)
			{LED2_OFF;} //�ر�LED2����ʾ�л���������˸���ʱ��ģʽ0
			else
			{LED2_ON;}//��LED2����ʾ�л���������˸���ʱ��ģʽ1
		}
		else//�̰����ı���˸���
		{
			switch(blink_time_change_mode)//ѡ����˸�����/��ģʽ
			{
				case 0:
					if(blink_time >= 5000)
					{
						blink_time = 5000;//�ָ��������˸���ʱ��5000ms
					}
					else
					{
						blink_time += 2000; //��˸���ʱ������2000ms
					}break;
				
				case 1:
					if(blink_time <= 1000)
					{
						blink_time = 5000;//�ָ��������˸���ʱ��5000ms
					}
					else
					{
						blink_time -= 2000;//��˸���ʱ�����2000ms
					}break;
				
				default:  break;
			}	
		}
}
