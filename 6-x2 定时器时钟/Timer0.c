#include <REGX52.H>

/**
  * @brief 定时器0初始化
  * @param  
  * @retval 
  */
void Timer0Init()
{
	TMOD&=0xF0;  //高四位不变
	TMOD|=0x01;  //设置定时器模式1 以及设置为定时方式 0
	
	TL0 = 0x66;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	
	TF0=0;  //定时器0溢出标志位
	TR0=1;  //定时器0运行控制位
	
	TF0=1;	//设置外部中断
	ET0=1;
	EA=1;
	PT0=0;
}