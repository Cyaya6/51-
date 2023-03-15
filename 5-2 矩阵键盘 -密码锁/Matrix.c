//矩阵按键
#include <REGX52.H>
#include "Delay.h"


/**
  * @brief  矩阵按键读取用户按下键码 按行扫描
  * @param  无
  * @retval KeyNumber 返回按下按键的数字 如按下 s1返回1
  如果按住按键不放，程序会停留在此函数，松手的一瞬间，返回按下的键码，没有按键按下时，默认为0。
  */
unsigned char Matrix()
{
	unsigned char KeyNumber=0;  //这里要注意
	//按行扫描
	P1=0xFF;  //给P1口全部置高电平
	P1_7=0;  //第一行
	
	if(P1_3==0)//第一列  也就是第一个按键
	{	Delay(200);  //延时20ms
		while(P1_3==0);  //检测松手
		Delay(200);
		KeyNumber=1;
	}	
	if(P1_2==0)//第一列  也就是第一个按键
	{	Delay(200);  //延时20ms
		while(P1_3==0);  //检测松手
		Delay(200);
		KeyNumber=2;
	}	
	if(P1_1==0)//第一列  也就是第一个按键
	{	Delay(200);  //延时20ms
		while(P1_3==0);  //检测松手
		Delay(200);
		KeyNumber=3;
	}	
	if(P1_0==0)//第一列  也就是第一个按键
	{	Delay(200);  //延时20ms
		while(P1_3==0);  //检测松手
		Delay(200);
		KeyNumber=4;
	}	
	
	//第二行
	P1=0xFF;  //给P1口全部置高电平
	P1_6=0;  //第一行
	
	if(P1_3==0)//第一列  也就是第一个按键
	{	Delay(200);  //延时20ms
		while(P1_3==0);  //检测松手
		Delay(200);
		KeyNumber=5;
	}	
	if(P1_2==0)//第一列  也就是第一个按键
	{	Delay(200);  //延时20ms
		while(P1_2==0);  //检测松手
		Delay(200);
		KeyNumber=6;
	}	
	if(P1_1==0)//第一列  也就是第一个按键
	{	Delay(200);  //延时20ms
		while(P1_1==0);  //检测松手
		Delay(200);
		KeyNumber=7;
	}	
	if(P1_0==0)//第一列  也就是第一个按键
	{	Delay(200);  //延时20ms
		while(P1_0==0);  //检测松手
		Delay(200);
		KeyNumber=8;
	}	
	
	//第三行
	P1=0xFF;  //给P1口全部置高电平
	P1_5=0;  //第一行
	
	if(P1_3==0)//第一列  也就是第一个按键
	{	Delay(200);  //延时20ms
		while(P1_3==0);  //检测松手
		Delay(200);
		KeyNumber=9;
	}	
	if(P1_2==0)//第一列  也就是第一个按键
	{	Delay(200);  //延时20ms
		while(P1_2==0);  //检测松手
		Delay(200);
		KeyNumber=10;
	}	
	if(P1_1==0)//第一列  也就是第一个按键
	{	Delay(200);  //延时20ms
		while(P1_1==0);  //检测松手
		Delay(200);
		KeyNumber=11;
	}	
	if(P1_0==0)//第一列  也就是第一个按键
	{	Delay(200);  //延时20ms
		while(P1_0==0);  //检测松手
		Delay(200);
		KeyNumber=12;
	}	
	
	//第四行
	P1=0xFF;  //给P1口全部置高电平
	P1_4=0;  //第一行
	
	if(P1_3==0)//第一列  也就是第一个按键
	{	Delay(200);  //延时20ms
		while(P1_3==0);  //检测松手
		Delay(200);
		KeyNumber=13;
	}	
	if(P1_2==0)//第一列  也就是第一个按键
	{	Delay(200);  //延时20ms
		while(P1_2==0);  //检测松手
		Delay(200);
		KeyNumber=14;
	}	
	if(P1_1==0)//第一列  也就是第一个按键
	{	Delay(200);  //延时20ms
		while(P1_1==0);  //检测松手
		Delay(200);
		KeyNumber=15;
	}	
	if(P1_0==0)//第一列  也就是第一个按键
	{	Delay(200);  //延时20ms
		while(P1_0==0);  //检测松手
		Delay(200);
		KeyNumber=16;
	}	
	return KeyNumber;
}