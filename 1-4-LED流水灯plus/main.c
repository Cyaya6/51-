#include <REGX52.H>

//ÑÓÊ±º¯Êý
void Delay1ms(unsigned int xms)		//@11.0592MHz
{
	unsigned char i, j;
while(xms)
{	
	i = 2;
	j = 199;
	do
	{
		while (--j);
	} while (--i);
	xms--;
}
	

}

void main()
{
		while(1)
{
	/*
	?????LED????? ??????
	*/
	
	//D1
	P2=0xFE;
	Delay1ms(1000);
	
	P2=0xFD;
	Delay1ms(1000);
	
	
	//D3
	P2=0xFB;
	Delay1ms(1000);
	
	
	//D4
	P2=0xF7;
	Delay1ms(100);
	
	
	P2=0xEF;
	Delay1ms(100);
	
	
	//D6
	P2=0xDF;
	Delay1ms(100);
	
	
	//D7
	P2=0xBF;
	Delay1ms(100);
	
	
	//D8
	P2=0x7F;
	Delay1ms(100);
	
}
}