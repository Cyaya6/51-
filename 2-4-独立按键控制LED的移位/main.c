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
	P2=~0x01;
	while(1)
	{
		if(P3_1==0)
		{
			Delay(20);
			while(P3_1==0);
			Delay(20);
			if(LedNumber>8)
			{
				LedNumber=0;
			}
			LedNumber++;
			P2=~(0x01<<LedNumber);  //~(0000 0001)  1111 1110
		}
		
		if(P3_0==0)
		{
			Delay(20);
			while(P3_0==0);
			Delay(20);
			if(LedNumber==0)   //如果减到0 再减会越界 0->255
			{
				LedNumber=7;
			}
			else
			{
				LedNumber--;	
			}
			P2=~(0x01<<LedNumber);  //~(0000 0001)  1111 1110
		}
	}
}
