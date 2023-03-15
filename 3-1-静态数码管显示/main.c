#include <REGX52.H>
#include<INTRINS.H>
//��ʱ����
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
																0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};  //P0�ڶ�Ӧ��LEd״̬
//��������ܵ�����P0�˿ڵ�д�� ʵ�ֵڼ���LED������ʾ�ĸ�����
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

//������
void main()
{
	while(1)
	{
		/*
		P2_2=1;   //ͨ��74H138 ������ 3-8�������� ������LED����ܵ�����״̬
		P2_3=0;
		P2_4=1;
		
		P0=0x5B;  //ͨ����P0�˿ڵ�д�� �����������LED��ʾ��λ��  ��8���ڣ��ֱ��ӦA-G
		*/
		NixieTube(1,1);
//		Delay(20);
		NixieTube(2,2);
//		Delay(20);
		NixieTube(3,3);
//		Delay(20);
	}
}