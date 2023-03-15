#include <REGX52.H>
#include "LCD1602.H"
#include "Delay.H"
int result=0;
void main()
{
	LCD_Init();  //LCD使用前初始化
	/*
	//LCD_ShowChar(1,1,'c');   //显示一个字符串
	LCD_ShowString(1,1,"cxw");
	LCD_ShowString(1,4,"Hello");
	LCD_ShowNum(2,1,250,3);   //显示一个数字
	LCD_ShowSignedNum(2,5,-123,3);   //显示有符号的数字
	LCD_ShowHexNum(2,10,0xA8,2);
	LCD_ShowBinNum(1,9,0xFF,8);  //0xFF 1111 1111 ->显示8位
	*/
	
	//LCD可以验证结果
	/*result=1+1;
	LCD_ShowNum(1,1,result,3);*/
	while(1)
	{
		//验证延时
		result=result+1;
		Delay(1000);
		LCD_ShowNum(1,1,result,3);
	}	 
}