#include <REGX52.H>
#include <Delay.h>
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
	Delay(1);  //动态显示就是改变延时 人眼频率达到消影
	P0=0x00;
}