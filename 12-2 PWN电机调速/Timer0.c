#include <REGX52.H>

/**
  * @brief 定时器0初始化
  * @param  
  * @retval 
  */
void Timer0Init()   //100us  10ms  11.0592MHZ
{
	TMOD&=0xF0;  //高四位不变
	TMOD|=0x01;  //设置定时器模式1 以及设置为定时方式 0
	
	TL0 = 0xA4;		//设置定时初值
	TH0 = 0xFF;		//设置定时初值
	
	TF0=0;  //定时器0溢出标志位
	TR0=1;  //定时器0运行控制位
	
	TF0=1;	//设置外部中断
	ET0=1;
	EA=1;
	PT0=0;
}

//中断函数
/*void Timer0_Rourine() interrupt 1
{
	static unsigned int T0count;
		TL0 = 0xA4;		//设置定时初值
	TH0 = 0xFF;		//设置定时初值
	T0count++;
	if(T0count>=1000)
	{
		T0count=0;
		P2_0=~P2_0;
	}
}*/