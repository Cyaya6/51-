#include <REGX52.H>
#include<INTRINS.H>
//延迟函数
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

//主函数
void main()
{
	unsigned char i;
	
	while(1)
	{
		//LED5亮
		P2_4=1;
		P2_3=0;
		P2_2=0;
		Delay(3);
		
		P0=0x01;  //让数码管的a段亮  0000 0001
		for(i=0;i<6;i++)
		{  
			
			P0<<=1;   //左移    0000  0010	
			P0=P1|0x01;  //让a段亮了之后 位或保留最低位 0000 0010 | 0000 0001 ->0000 0011
		}
	}
}