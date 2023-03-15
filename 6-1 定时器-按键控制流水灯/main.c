#include <REGX52.H>
#include "Timer0.H"
#include "Key.H"

unsigned char KeyNum;
void main()
{
	//Timer0Init();
	while(1)
	{
		KeyNum=Key();
		if(KeyNum==1)P2_1=~P2_1;
		if(KeyNum==2)P2_2=~P2_2;
		if(KeyNum==3)P2_3=~P2_3;
		if(KeyNum==4)P2_4=~P2_4;
	}
}
//unsigned int T0Count;
//void Timer0_Routine() interrupt 1
//{
//	//中断服务程序
//	TL0 = 0x18;		//设置定时初值
//	TH0 = 0xFC;		//设置定时初值   64535/256 ->252 ->FC
//	T0Count++;   //每触发一次中断 就加1
//	if(T0Count>=1000)
//	{    //1s  一次定时是1ms
//		T0Count=0;
//		P2_0=~P2_0;
//	}
//	
//}
