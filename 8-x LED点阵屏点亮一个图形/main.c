#include <REGX52.H>
#include "Delay.h"
#include "Matrix_LED.h"

sbit RCK=P3^5;   //RCLK
sbit SCK=P3^6;	//SRCLK
sbit SER=P3^4;	//SER

void main()
{
	void MatrixLED_Init();  //点阵屏初始化
	while(1)
	{
		MatrixLed_ShowColumn(0x80,0);
		MatrixLed_ShowColumn(0x40,1);
		MatrixLed_ShowColumn(0x20,2);
		MatrixLed_ShowColumn(0x10,3);
		MatrixLed_ShowColumn(0x08,4);
		MatrixLed_ShowColumn(0x04,5);
		MatrixLed_ShowColumn(0x02,6);
		MatrixLed_ShowColumn(0x01,7);
	}
}
