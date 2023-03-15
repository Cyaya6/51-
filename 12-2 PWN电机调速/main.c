#include <REGX52.H>
#include "Delay.h"
#include "Key.h"
#include "Timer0.h"
#include "NixieTube.h"

sbit motor=P1^0;   //电机端口
unsigned char Counter,Compare;   //counter 0-100 指的是频率 comapre 指的是占空比 高电平时间   Compare 最大值为100us
unsigned char KeyNum,Speed;
void main()
{
	Timer0Init();
	Compare=5;
	while(1)
	{
		KeyNum=Key();
		if(KeyNum==1)
		{
			Speed++;
			if(Speed>3){Speed=0;}
			if(Speed==0){Compare=0;}   //compare 指的就是占空比 
			if(Speed==1){Compare=50;}   //5%的占空比
			if(Speed==2){Compare=75;}
			if(Speed==3){Compare=100;}
		}
		NixieTube(8,Speed);
	}
}

void Timer0_Rourine() interrupt 1   //每隔100us进来一次
{
	TL0 = 0xA4;		//设置定时初值
	TH0 = 0xFF;		//设置定时初值
	Counter++;
	if(Counter>=100){Counter=0;}
	if(Counter<Compare)
	{
		motor=1;
	}
	else
	{
		motor=0;
	}
}