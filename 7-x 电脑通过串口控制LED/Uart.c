#include <REGX52.H>

/**
	* @brief 	串口初始化，配置串口相关的寄存器 PCON SCON  定时器1 不开启中断
  * @param  无 
  * @retval 无
  */
void UartInit(void)		//4800bps@11.0592MHz
{
	PCON &= 0x7F;		//波特率不倍速
	SCON = 0x50;		//*****8位数据,可变波特率   REN这位置1  SM0 SM1 SM2 REN ->0 1 0 1 0000
	
	TMOD &= 0x0F;		//清除定时器1模式位
	TMOD |= 0x20;		//设定定时器1为8位自动重装方式
	TL1 = 0xFA;		//设定定时初值
	TH1 = 0xFA;		//设定定时器重装值
	
	ET1 = 0;		//禁止定时器1中断
	TR1 = 1;		//启动定时器1
	
}

// 写入SBUF ,写入的是发送寄存器，  读取SBUF时，读出的是接受寄存器  即读出的时候要配置串口中断
void Uart_Init()  //配置串口相关的寄存器
{
	SCON=0x50;    //REN这位置1  SM0 SM1 SM2 REN ->0 1 0 1 0000
	PCON &= 0x7F;
	
	//配置定时器1
	TMOD&=0x0F;		//高四位清零
	TMOD|=0x20;		//配置定时器1的模式  
	TL1 = 0xFA;		//设定定时初值
	TH1 = 0xFA;		//设定定时器重装值
	
	ET1 = 0;		//禁止定时器1中断  由于这里不需要用到中断所以，没有配置中断有关的寄存器
	TR1 = 1;		//启动定时器1
	
	ES=1;  //配置串口中断
	EA=1;
}

/**
  * @brief 	向串口写入一个字节的数据
  * @param  byte 要发送的一个字节数据
  * @retval 无
  */
void UartSendByte(unsigned char byte)
{
	//写入数据，只需要向SBUF中写入数据就可以了
	SBUF=byte;
	while(TI==0);  //TI用来判断是否由硬件置1
	TI=0;  //发送数据发完了，用软件置0
}


/*  串口中断函数的模板
void UART_Routine() interrupt 4  //串口中断子程序
	//电脑向串口发送数据，产生串口接收中断  
{
	if(RI==1)   //产生了串口接收中断
	{   //需要这条语句的原因是发送数据也会产生中断
		//在这里进行操作
		RI=0;   //RI置0，清除中断申请
	}
}
*/