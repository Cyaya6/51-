#include <REGX52.H>
#include<INTRINS.H>
//延时函数
void Delay(unsigned int xms)		//@11.0592MHz
{
	unsigned char i, j;

	while(xms)
	{
		_nop_();
	i = 2;
	j = 199;
	do
	{
		while (--j);
	} while (--i);
	xms--;
	}
}

//主函数
void main()
{
	unsigned char LedNumber=0;
	while(1)
	{
		if(P3_1==0)
		{
			Delay(20);
			while(P3_1==0);  //检测松手
			Delay(20);
			// 1111 1111
			//1.可以直接P2-- 可以显示二进制变化
			//P2--;  //1111 1110 依次递减 到25次之后默认回0
			
			//2.采用变量来控制P2的移位
			LedNumber++;   //0000 0001
			P2=~NUMber++;  //P2 = 1111 1110  LEd1就点亮了
		}
	}
}
