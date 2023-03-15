#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "Matrix.h"

unsigned char KeyNum;
void main()
{
	LCD_Init(); //初始化LCD
	LCD_ShowString(1,1,"Matrix");
	while(1)
	{
		KeyNum=Matrix();
		LCD_ShowNum(2,1,KeyNum,3);
	}
}
