#include <REGX52.H>
#include<INTRINS.H>
//LED ��ˮ��
//��ʱ����
void Delay500ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	_nop_();
	i = 4;
	j = 129;
	k = 119;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}


//������
void main()
{
	while(1)
{
	/*
	��ʵ������LED���������� Ȼ��������ʱ
	*/
	
	//D1
	P2=0xFE;
	Delay500ms();
	
	P2=0xFD;
	Delay500ms();
	
	
	//D3
	P2=0xFB;
	Delay500ms();
	
	
	//D4
	P2=0xF7;
	Delay500ms();
	
	
	P2=0xEF;
	Delay500ms();
	
	
	//D6
	P2=0xDF;
	Delay500ms();
	
	
	//D7
	P2=0xBF;
	Delay500ms();
	
	
	//D8
	P2=0x7F;
	Delay500ms();
	
}
}
