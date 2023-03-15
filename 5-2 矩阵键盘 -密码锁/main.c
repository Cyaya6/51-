#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "Matrix.h"

unsigned char KeyNum;  //按下矩阵键盘返回的数值 如按下s1返回1
unsigned int PassWord=0,count=0;
void main()
{
	LCD_Init(); //初始化LCD
	LCD_ShowString(1,1,"PassWord");
	while(1)
	{
		KeyNum=Matrix();
		if(KeyNum)
		{
			if(KeyNum<=10)  //密码区 s1-s10为输入密码区
			{
				if(count<4)  //如果输入次数小于4
				{
				PassWord*=10;     //密码左移一位
				PassWord+=KeyNum%10;   //1-9 对10取余 还是1-9 10取余 就是1 
				//就是让密码不断左移
				count++;  //每一次移位后计数
				}
				
				LCD_ShowNum(2,1,PassWord,4);   //在LCD上显示密码  更新显示
			}
		 
			if(KeyNum==11)   //如果按下s11 确认密码
			{
				if(PassWord==1234)
				{
					LCD_ShowString(1,12,"  OK!");  //输入正确
					PassWord=0;  //清除密码
					count=0;    //清除计数
					LCD_ShowNum(2,1,PassWord,4);   //更新显示
				}
				else
				{
					LCD_ShowString(1,12,"ERROR");
					PassWord=0;  //清除密码
					count=0;    //清除计数
					LCD_ShowNum(2,1,PassWord,4);   //更新显示
				} 
			}
			
			if(KeyNum==12)   //按下按键s12 取消键  按位取消  例如1234 ->0123
			{
					PassWord/=10;  //清除密码
					count--;    //清除计数
					LCD_ShowNum(2,1,PassWord,4);   //更新显示
			}
		} 
	}
}
