#include <REGX52.H>
#include "LCD1602.h"
#include "DS1302.h"
#include "Delay.h"
#include "Key.h"
#include "Timer0.h"

unsigned char KeyNum,MODE,TimeSetSelect,TimeSetFlashFlag;

void TimerShow()
{
	DS1302_ReadTime();//读取时间
	LCD_ShowNum(1,1,DS1302Time[0],2);	//显示年
	LCD_ShowNum(1,4,DS1302Time[1],2);	//显示月
	LCD_ShowNum(1,7,DS1302Time[2],2);//显示日
	LCD_ShowNum(2,1,DS1302Time[3],2);	//显示时
	LCD_ShowNum(2,4,DS1302Time[4],2);	//显示分
	LCD_ShowNum(2,7,DS1302Time[5],2);		//显示秒
		//Delay(500);
}
void TimerSet()//时间设置功能
{
	if(KeyNum==2)  //选择修改位操作 按键2按下
	{
		TimeSetSelect++;   //设置选择位加一	
		TimeSetSelect%=6;   //TimeSetSelect>5 清零
	}
	if(KeyNum==3)  //加操作 按键3按下
	{
		DS1302Time[TimeSetSelect]++;
		if(DS1302Time[0]>99){DS1302Time[0]=0;}  //年越界判断
		if(DS1302Time[1]>12){DS1302Time[1]=1;}  //月 
		
		//判断日是否越界
		if(DS1302Time[1]==1||DS1302Time[1]==3||DS1302Time[1]==5||DS1302Time[1]==7||
					DS1302Time[1]==8||DS1302Time[1]==10||DS1302Time[1]==12)
		{
		if(DS1302Time[2]>31){DS1302Time[2]=1;}   //31天的月份
		}  
		else if(DS1302Time[1]==3||DS1302Time[1]==4||DS1302Time[1]==6||DS1302Time[1]==9||
			DS1302Time[1]==11)
		{
		if(DS1302Time[2]>30){DS1302Time[2]=1;}   //30天的月份
		}
		else if(DS1302Time[1]==2)
		{
			if(DS1302Time[0]%4==0&&DS1302Time[0]%100!=0)
			{
				if(DS1302Time[2]>29){DS1302Time[2]=1;}  //闰年2月29天
			}
			else
			{
				if(DS1302Time[2]>28){DS1302Time[2]=1;}  //非闰年2月28天
			}
		}
		
		if(DS1302Time[3]>23){DS1302Time[3]=0;}  //小时越界判断
		if(DS1302Time[4]>59){DS1302Time[4]=0;}  //分钟越界判断
		if(DS1302Time[5]>59){DS1302Time[5]=0;}  //秒越界判断
	}
	if(KeyNum==4)  //减操作
	{
		DS1302Time[TimeSetSelect]--;
				if(DS1302Time[0]<0){DS1302Time[0]=99;}  //年越界判断
		if(DS1302Time[1]<1){DS1302Time[1]=12;}  //月 
		
		//判断日是否越界
		if(DS1302Time[1]==1||DS1302Time[1]==3||DS1302Time[1]==5||DS1302Time[1]==7||
					DS1302Time[1]==8||DS1302Time[1]==10||DS1302Time[1]==12)
		{
		if(DS1302Time[2]<1){DS1302Time[2]=31;}   //31天的月份
		if(DS1302Time[2]>31){DS1302Time[2]=1;}
		}  
		else if(DS1302Time[1]==3||DS1302Time[1]==4||DS1302Time[1]==6||DS1302Time[1]==9||
			DS1302Time[1]==11)
		{
		if(DS1302Time[2]<1){DS1302Time[2]=30;}   //30天的月份
		if(DS1302Time[2]>30){DS1302Time[2]=1;} 
		}
		else if(DS1302Time[1]==2)
		{
			if(DS1302Time[0]%4==0&&DS1302Time[0]%100!=0)
			{
				if(DS1302Time[2]<1){DS1302Time[2]=29;}  //闰年2月29天
				if(DS1302Time[2]>29){DS1302Time[2]=1;} 
			}
			else
			{
				if(DS1302Time[2]<1){DS1302Time[2]=28;}  //非闰年2月28天
				if(DS1302Time[2]>28){DS1302Time[2]=1;} 
			}
		}
		
		if(DS1302Time[3]<0){DS1302Time[3]=23;}  //小时越界判断
		if(DS1302Time[4]<0){DS1302Time[4]=59;}  //分钟越界判断
		if(DS1302Time[5]<0){DS1302Time[5]=59;}
	}
	//更新显示 根据TimeSetSelect和TimeSetFlashFlag判断可完成闪烁功能
	if(TimeSetSelect==0&&TimeSetFlashFlag==1){LCD_ShowString(1,1,"  ");}
	else{LCD_ShowNum(1,1,DS1302Time[0],2);}
	
	if(TimeSetSelect==1&&TimeSetFlashFlag==1){LCD_ShowString(1,4,"  ");}
	else{LCD_ShowNum(1,4,DS1302Time[1],2);}
	
	if(TimeSetSelect==2&&TimeSetFlashFlag==1){LCD_ShowString(1,7,"  ");}
	else{LCD_ShowNum(1,7,DS1302Time[2],2);}
	
	if(TimeSetSelect==3&&TimeSetFlashFlag==1){LCD_ShowString(2,1,"  ");}
	else{LCD_ShowNum(2,1,DS1302Time[3],2);}
	
	if(TimeSetSelect==4&&TimeSetFlashFlag==1){LCD_ShowString(2,4,"  ");}
	else{LCD_ShowNum(2,4,DS1302Time[4],2);}

	if(TimeSetSelect==5&&TimeSetFlashFlag==1){LCD_ShowString(2,7,"  ");}
	else{LCD_ShowNum(2,7,DS1302Time[5],2);}
	
		
	
	LCD_ShowNum(2,10,TimeSetSelect,2);
	LCD_ShowNum(2,13,TimeSetFlashFlag,2);
}

void main()  //主函数
{
	LCD_Init();
	DS1302_Init();
	Timer0Init();
	LCD_ShowString(1,1,"  -  -");	//静态字符初始化显示
	LCD_ShowString(2,1,"  :  :");
	DS1302_SetTime();
	
	while(1)
	{
		KeyNum=Key();
		if(KeyNum==1)  //按下key1 改变模式 0-> 时间显示模式  1-> 时间修改模式
		{
			if(MODE==0){MODE=1;TimeSetSelect=0;}  //功能切换
			else if(MODE==1){MODE=0;DS1302_SetTime();}
		}
		switch(MODE)   //根据MODE的值选择不同的功能
		{
			case 0: TimerShow(); break;
			case 1: TimerSet(); break;
		}
	}
}


void Timer0_Rourine() interrupt 1
{
	static unsigned int T0count;
	TL0 = 0x66;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	T0count++;
	if(T0count>=500)  //每500ms取反一次
	{
		T0count=0;
		TimeSetFlashFlag=!TimeSetFlashFlag;
		//!逻辑取反  1->0  0->1
		//~按位取反  0xFF->0x00  0xFE->0x01
	}
}