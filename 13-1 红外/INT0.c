#include <REGX52.H>
void Int0_Init()
{
	IT0=1;  //下降沿触发
	IE0=0;
	EX0=1;
	EA=1;
	PX0=1;   //高优先级
}

//void Int0_Routine() interrupt 0
//{
//	Num++;
//}