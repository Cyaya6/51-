#include <REGX52.H>
#include "LCD1602.h"
#include "DS1302.h"
#include "Delay.h"

void main()
{
	LCD_Init();
	DS1302_Init();
	DS1302_SetTime();
	
	while(1)
	{
		DS1302_ReadTime();
		LCD_ShowNum(1,1,DS1302Time[0],2);	
		LCD_ShowString(1,3,"-");
		LCD_ShowNum(1,4,DS1302Time[1],2);	
		LCD_ShowString(1,6,"-");
		LCD_ShowNum(1,7,DS1302Time[2],2);	
		
		LCD_ShowNum(2,1,DS1302Time[3],2);	
		LCD_ShowString(2,3,":");
		LCD_ShowNum(2,4,DS1302Time[4],2);	
		LCD_ShowString(2,6,":");
		LCD_ShowNum(2,7,DS1302Time[5],2);		//把BCD码转换为十进制
		//Delay(500);
	}
}
