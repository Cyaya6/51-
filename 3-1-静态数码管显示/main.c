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
																0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};  //P0口对应的LEd状态
//控制数码管点亮和P0端口的写入 实现第几个LED亮起显示哪个内容
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

//主函数
void main()
{
	while(1)
	{
		/*
		P2_2=1;   //通过74H138 译码器 3-8线译码器 来控制LED数码管的亮灭状态
		P2_3=0;
		P2_4=1;
		
		P0=0x5B;  //通过对P0端口的写入 来控制数码管LED显示的位置  有8个口，分别对应A-G
		*/
		NixieTube(1,1);
//		Delay(20);
		NixieTube(2,2);
//		Delay(20);
		NixieTube(3,3);
//		Delay(20);
	}
}