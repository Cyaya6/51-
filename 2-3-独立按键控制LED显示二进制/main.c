#include <REGX52.H>
#include<INTRINS.H>
//��ʱ����
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

//������
void main()
{
	unsigned char LedNumber=0;
	while(1)
	{
		if(P3_1==0)
		{
			Delay(20);
			while(P3_1==0);  //�������
			Delay(20);
			// 1111 1111
			//1.����ֱ��P2-- ������ʾ�����Ʊ仯
			//P2--;  //1111 1110 ���εݼ� ��25��֮��Ĭ�ϻ�0
			
			//2.���ñ���������P2����λ
			LedNumber++;   //0000 0001
			P2=~NUMber++;  //P2 = 1111 1110  LEd1�͵�����
		}
	}
}
