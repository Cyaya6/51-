#include <REGX52.H>
void Timer0Init()
{
	TMOD&=0xF0;  //高四位不变
	TMOD|=0x01;  //设置定时器模式1 以及设置为定时方式 0
	
	TL0 = (65536-1000)%256;		//设置定时初值
	TH0 = (65536-1000)/256;		//设置定时初值
	
	TF0=0;  //定时器0溢出标志位
	TR0=1;  //定时器0运行控制位
	
	TF0=1;	//设置外部中断
	ET0=1;
	EA=1;
	PT0=0;
}
void main()
{
	Timer0Init();
	while(1)
{
	
}
}

//中断服务子程序
void Timer0_Rourine() interrupt 1
{
	static unsigned char count;
	TL0 = (65536-1000)%256;		//设置定时初值
	TH0 = (65536-1000)/256;		//设置定时初值
	count++;
		if (count >=1000)   
		{
			count = 0;
			P2=0x00;
		}	
}
