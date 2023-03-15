#include <REGX52.H>
#include "Delay.h"
#include "Timer0.h"
#include "LCD1602.h"
unsigned char sec=55,min=59,hour=23;
void main()
{
	LCD_Init();  //LCD初始化
	LCD_ShowString(1,1,"COLCK:");
	Timer0Init();  //定时器0初始化
	while(1)
	{
		LCD_ShowNum(2,1,hour,2); 
		LCD_ShowString(2,3,":");
		LCD_ShowNum(2,4,min,2);
		LCD_ShowString(2,6,":");
		LCD_ShowNum(2,7,sec,2);
	}
}


void TimerRoutine() interrupt 1
{
	static unsigned int T0Count;
	//当触发中断后，每次中断结束后，初始值还是为64535 即1ms
	TL0 = 0x66;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	T0Count++;
	if(T0Count>=1000)  //一次是1ms，*1000就是一秒    
	{
		T0Count=0;
		sec++;
		if(sec>=60)
		{
			sec=0;
			min++;
			if(min>=60)
			{
				min=0;
				hour++;
				if(hour>=24)
				{
					hour=0;
					sec=0;
					min=0;
				}
			}
		}
	}
}