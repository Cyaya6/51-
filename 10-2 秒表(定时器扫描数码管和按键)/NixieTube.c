#include <REGX52.H>
#include <Delay.h>
unsigned char NixieTubeBuffer[9]={0,10,10,10,10,10,10,10,10};
unsigned char NixieTubeNumber[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,
																0x6f,0x00,0x40};  //P0口对应的LEd状态
void NixieTube_SetBuf(unsigned char location,unsigned char context)
{
	NixieTubeBuffer[location]=context;
}
																
//控制数码管点亮和P0端口的写入 实现第几个LED亮起显示哪个内容
void NixieTube_Scan(unsigned char location,unsigned char context)
{
	P0=0x00;
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
	
}

void Nixie_Loop()
{
	static unsigned char i=1;
	NixieTube_Scan(i,NixieTubeBuffer[i]);
	i++;
	if(i>=9){i=1;}
}
