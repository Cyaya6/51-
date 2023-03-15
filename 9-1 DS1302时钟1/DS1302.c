#include <REGX52.H>

//DS1302引脚定义
sbit DS1302_SCLK=P3^6;
sbit DS1302_IO=P3^4;
sbit DS1302_CE=P3^5;

//寄存器读写地址定义
#define DS1302_SECOND_WRITE  0x80			//秒
#define DS1302_SECOND_READ   0x81  
#define DS1302_MIN_WRITE     0x82		//分
#define DS1302_MIN_READ   	 0x83
#define DS1302_HOUR_WRITE    0x84		//时
#define DS1302_HOUR_READ   	 0x85
#define DS1302_DATE_WRITE    0x86		//日
#define DS1302_DATE_READ   	 0x87
#define DS1302_MONTH_WRITE   0x88		//月
#define DS1302_MONTH_READ    0x89
#define DS1302_DAY_WRITE     0x8A		//星期几
#define DS1302_DAY_READ   	 0x8B
#define DS1302_YEAR_WRITE    0x8C	//年
#define DS1302_YEAR_READ   	 0x8D
#define DS1302_WP     			 0x8E	  //写入保护

//时间数组  年-月-日-时-分-秒-星期几
unsigned char DS1302Time[]={22,10,12,16,05,55,3};   //2022-10-10-16:59-3week

/**
  * @brief DS1302初始化
  * @param  无
  * @retval 无
  */
void DS1302_Init()
{
	DS1302_CE=0;
	DS1302_SCLK=0;
}

/**
  * @brief 向DS1302写入一个字节
  * @param  command 写入的命令字或地址
	* @param  Date    写入的数据
  * @retval 无
  */
void DS1302_WriteByte(unsigned char command,unsigned char Data)  //命令字  数据 写操作
{
	unsigned char i;
	DS1302_CE=1;  //CE置1 可以读取数据
	
	for(i=0;i<8;i++)  //将command的八位都读进IO口
	{
	DS1302_IO=(command&0x01<<i);  //取出command的第一位
	DS1302_SCLK=1;   //一个上升沿
	DS1302_SCLK=0;
	}
	
	for(i=0;i<8;i++)  //将Data的八位都读进IO口
	{
	DS1302_IO=(Data&0x01<<i);  //取出command的第一位
	DS1302_SCLK=1;   //一个上升沿
	DS1302_SCLK=0;
	}
	
	DS1302_CE=0;  //读取数据完成  
}

/**
  * @brief DS1302读一个字节
  * @param  command 命令字或者地址
  * @retval 读取的字节数据
  */
unsigned char DS1302_ReadByte(unsigned char command)//读操作
{
	unsigned char i,Data=0x00;
	DS1302_CE=1;  //CE置1 可以读取数据
	//command|=0x01;  //读到的命令 最后一位置1 也就是直接
	for(i=0;i<8;i++)  //将command的八位都读进IO口
	{
	DS1302_IO=command&(0x01<<i);  //取出command的第一位
	DS1302_SCLK=0;  //改变电平状态
	DS1302_SCLK=1;
	}
	
	//读取DS1302里的数据，输出给IO口
	for(i=0;i<8;i++)
	{
	DS1302_SCLK=1;  //改变电平状态
	DS1302_SCLK=0;
	if(DS1302_IO){Data|=(0x01<<i);}
	}
	DS1302_CE=0;
	DS1302_IO=0;	//读取后将IO设置为0，否则读出的数据会出错
	return Data;
}

/**
  * @brief 设置时间  向DS1302写操作 调用之后，DS1302_Time数组的数字会被设置到DS1302中
  * @param  无
  * @retval 无
  */
void DS1302_SetTime()
{
	DS1302_WriteByte(DS1302_WP,0x00);  
	//解除芯片写入保护  如果读出时间为一个大于59并且不动的数，芯片很有可能处于写保护状态
	DS1302_WriteByte(DS1302_DAY_WRITE,DS1302Time[6]/10*16+DS1302Time[6]%10);  //读取的是BCD码
	DS1302_WriteByte(DS1302_SECOND_WRITE,DS1302Time[5]/10*16+DS1302Time[5]%10);
	DS1302_WriteByte(DS1302_MIN_WRITE,DS1302Time[4]/10*16+DS1302Time[4]%10);
	DS1302_WriteByte(DS1302_HOUR_WRITE,DS1302Time[3]/10*16+DS1302Time[3]%10);
	DS1302_WriteByte(DS1302_DATE_WRITE,DS1302Time[2]/10*16+DS1302Time[2]%10);
	DS1302_WriteByte(DS1302_MONTH_WRITE,DS1302Time[1]/10*16+DS1302Time[1]%10);
	DS1302_WriteByte(DS1302_YEAR_WRITE,DS1302Time[0]/10*16+DS1302Time[0]%10);
	DS1302_WriteByte(DS1302_WP,0x80);
	
	/*
	DS1302_WriteByte(0x8E,0x00);  //解除芯片写入保护  如果读出时间为一个大于59并且不动的数，芯片很有可能处于写保护状态
	DS1302_WriteByte(0x80,0x55);  //对秒进行写入
	//写入的数是以bcd码来进位 最后显示时会转换为十进制  0000 1001  9 -> 0001 0000 10(d)  ->16
	DS1302_WriteByte(0x82,0x59);  //对分钟进行写入
	DS1302_WriteByte(0x84,0x08);  //对小时进行写入
	*/
}


/**
  * @brief 读取时间  向DS1302读操作 调用之后，DS1302_Time数组的数字会被读取到DS1302中
  * @param  无
  * @retval 无
  */
void DS1302_ReadTime()
{
	unsigned char temp;
	
	temp=DS1302_ReadByte(DS1302_YEAR_READ);
	DS1302Time[0]=temp/16*10+temp%16;
	
	temp=DS1302_ReadByte(DS1302_MONTH_READ);
	DS1302Time[1]=temp/16*10+temp%16;
	
	temp=DS1302_ReadByte(DS1302_DATE_READ);
	DS1302Time[2]=temp/16*10+temp%16;
	
	temp=DS1302_ReadByte(DS1302_HOUR_READ);
	DS1302Time[3]=temp/16*10+temp%16;
	
	temp=DS1302_ReadByte(DS1302_MIN_READ);
	DS1302Time[4]=temp/16*10+temp%16;
	
	temp=DS1302_ReadByte(DS1302_SECOND_READ);
	DS1302Time[5]=temp/16*10+temp%16;
	
	temp=DS1302_ReadByte(DS1302_DAY_READ);
	DS1302Time[6]=temp/16*10+temp%16;
}