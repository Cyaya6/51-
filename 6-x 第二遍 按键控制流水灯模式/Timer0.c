#include <REGX52.H>

//配置定时器0的寄存器
//手动配置
void Timer0_Init()
{
	TMOD&=0xF0;  //选定模式1 M1 M0->0 1
	TMOD|=0x01;
	
	TF0=0;
	TR0=1;  //定时器0是否开启
	
	TH0=64535/256;
	TL0=64535%256;
	
	ET0=1;
	EA=1;
	PT0=0;
}

//STC软件自动生成
/**
  * @brief 定时器0初始化  1000微秒@12.0000MHz
  * @param  无
  * @retval 无
  */
void Timer0Init(void)		
{
	//AUXR &= 0x7F;		//定时器时钟12T模式
	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;		//设置定时器模式   模式1

	TL0 = 0x66;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
	
	ET0=1;   //中断
	EA=1;
	PT0=0;
}


//中断函数
/*void Timer0_Rourine() interrupt 1
{
	static unsigned int T0count;
	TL0 = 0x66;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	T0count++;
	if(T0count>=1000)
	{
		T0count=0;
		P2_0=~P2_0;
	}
}*/