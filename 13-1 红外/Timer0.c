#include <REGX52.H>
void Timer0Init()
{
	TMOD&=0xF0;  //高四位不变
	TMOD|=0x01;  //设置定时器模式1 以及设置为定时方式 0
	
	TL0 = 0;		//设置定时初值
	TH0 = 0;		//设置定时初值
	
	TF0=0;  //定时器0溢出标志位
	TR0=0;  //定时器0运行控制位  定时器0不计时
}
void Timer0_SetCounter(unsigned int Value)
{
	TH0=Value/256;
	TL0=Value%256;
}

unsigned  int TimerGetCount()
{
	return (TH0<<8)|TL0;
}

void Timer0_Run(unsigned char Flag)
{
	TR0=Flag;
}