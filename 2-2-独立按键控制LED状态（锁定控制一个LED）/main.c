#include <REGX52.H>
#include<INTRINS.H>

//延时
void Delay(unsigned char xms)		//@11.0592MHz
{
	unsigned char i, j;   //1ms  经过自己调试后较为精准的延时程序

	while(xms--)
	{
		//_nop_();
	i = 2;
	j = 236;
	do
	{
		while (--j);
	} while (--i);
	}
}


void main()
{
	while(1)
	{
		if(P3_1==0)  
		{
			Delay(20);  
			while(P3_1==0)  
			{
			}
			Delay(20);  	
			P2_0=~P2_0;  
		}
	}
}
