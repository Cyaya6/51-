#include <REGX52.H>
#include "Delay.h"

//定义74HC595 控制管脚
sbit RCK=P3^5;  //存储寄存器时钟输入  RCLK
sbit SCK=P3^6;	//移位寄存器时钟输入  SRCLK
sbit SER=P3^4;  //串行数据输入

//笑脸的行数据
//unsigned char rowArray[]={0x3C,0x42,0xA9,0x85,0x85,0xA9,0x42,0x3E};
//unsigned char columnArray[]={0x3C,0x42,0xA5,0x81,0xA5,0x99,0x43,0x3C};


/**
  * @brief 向74H595中写入一个字节的数据
  * @param Byte 要写入的字节
  * @retval 无
  */
void _74H595_WriteByte(unsigned char byte)  //向74H595中写入一个字节的数据
{
//	SER=0x80;   //1000 0000 串行输入一个数据 最低位置1
//	SCK=1;
//	SCk=0;
	unsigned char i;
	for(i=0;i<8;i++)
	{
		SER=byte&(0x80>>i);    //逐步向右移位  0x40 0x20
		SCK=1;   //上升沿
		SCK=0;
	}
	RCK=1;
	RCK=0;  //存储寄存器时钟上升沿将前面写入到寄存器的数据输出
}

/**
  * @brief LED点阵屏的初始化
  * @param  无
  * @retval 无
  */
void Matrix_Init()
{
	SCK=0;
	RCK=0;
}


/**
  * @brief LED点阵屏显示一列数据
	* @param row 选择的列显示的数据  高位在上 1为亮
	* @param column 要选择的列（0~7） 0在最左边
  * @retval 无
  */
void MatrixLed_ShowColumn(unsigned char row,column)
{
	_74H595_WriteByte(row);  //控制行
	//if(column==0) 	{P0=~0x80};  后面依次递增
	P0=~(0x80>>column);  //控制列  
	Delay(1);
	P0=0xFF;
}