#include <REGX52.H>
#include<INTRINS.H>
//延时函数
void Delay(unsigned char xms)		//@11.0592MHz
{
	unsigned char i, j;

	while(xms--)
	{
		_nop_();
	i = 2;
	j = 199;
	do
	{
		while (--j);
	} while (--i);
	}
}

unsigned char NixieTubeNumber[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,
																0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};  
//数码管显示
void NixieTube(unsigned char location,unsigned char context)
{
	switch(location)
	{
		case 1:
			P2_4=0;P2_3=0;P2_2=0;break;
		case 2:
			P2_4=0;P2_3=0;P2_2=1;break;
		case 3:
			P2_4=0;P2_3=1;P2_2=0;break;
		case 4:
			P2_4=0;P2_3=1;P2_2=1;break;
		case 5:
			P2_4=1;P2_3=0;P2_2=0;break;
		case 6:
			P2_4=1;P2_3=0;P2_2=1;break;
		case 7:
			P2_4=1;P2_3=1;P2_2=0;break;
		case 8:
			P2_4=1;P2_3=1;P2_2=1;break;
	}
	P0=NixieTubeNumber[context];
	Delay(5);
	P0=0x00;
}


void main()
{
	unsigned char i,j;
	//8位数码管从最低位到最高位 ，逐位显示0-7 不断循环
	for(j=0;j<8;j++)
	{
		for(i=0;i<8;i++){
		Delay(100);
		NixieTube(j,i);
		}
	}
	
}