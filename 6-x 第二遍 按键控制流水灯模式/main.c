#include <REGX52.H>
#include "Timer0.h"
#include "Key.h"
#include <INTRINS.h>

unsigned char keyNum,LEDMode;
void main()
{
	P2=0xFE;  //设置初始亮灯的位置
	Timer0Init();   //定时器零初始化
	while(1)
	{
		keyNum=Key();  //获取按键所对应的键码
		if(keyNum)
		{
			if(keyNum==1)
			{
				LEDMode++;
				if(LEDMode>=2)LEDMode=0;
			}
		}
	}
}


void Timer0_Rourine() interrupt 1
{
	static unsigned int T0count;
	//当触发中断后，每次中断结束后，初始值还是为64535 即1ms
	TL0 = 0x66;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	T0count++;
	if(T0count>=500)
	{
		T0count=0;
		if(LEDMode==0)
			P2=_crol_(P2,1);
		if(LEDMode==1)
			P2=_cror_(P2,1);
	}
}
