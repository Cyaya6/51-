#include <REGX52.H>
#include "Delay.h"

sbit RCK=P3^5;   //RCLK
sbit SCK=P3^6;	//SRCLK
sbit SER=P3^4;	//SER
#define MATRIX_LED_PORT P0

/**
  * @brief 	向74H595中写入一个字节数据
  * @param  byte 要写入的字节数据 即输出锁存位
  * @retval 无
  */
void _74H595_WriteByte(unsigned char byte)  //byte 就是Dpa-Dph 向八个引脚赋值 
{
	unsigned char i;
	for(i=0;i<8;i++)  //移出byte的每一位
	{
		SER=byte&(0x80>>i);  //取出byte的第八位
		SCK=1;  //得到上升沿  0->1  移位
		SCK=0;  //清零，为下一次移位做准备	
	}	
	RCK=1;   //上升沿 byte已经全部移到移位寄存器中了 可以传给输出缓存
	RCK=0;   //清零  关闭锁存 
}

/**
  * @brief 	选择行列，在LED点阵屏中显示
  * @param  row 要选则的行 由自己写入 高电平有效  column 要选择的列 范围0-7 
  * @retval 无	
  */
void MatrixLed_ShowColumn(unsigned char row,unsigned char column)
{
	_74H595_WriteByte(row);  //选择行
	MATRIX_LED_PORT=~(0x80>>column);  //选择列
	
//	if(column==0){P0=~0x80}
//	if(column==0){P0=~0x40}
	Delay(1);  //延时
	MATRIX_LED_PORT=0xFF;   //位清零   段选 位选 位清零 不断重复
}

/**
* @brief 对上升沿进行初始化  改变相应的位 获得一个上升沿
  * @param  无
  * @retval 无
  */
void MatrixLED_Init()
{
	SCK=0;   //串行时钟初始化
	RCK=0;   //初始化移位寄存器时钟
}