#include <REGX52.H>
#include "Delay.h"
#include "Uart.h"

void main()
{
	Uart_Init();
	
	while(1)
	{
		
	}
}


void UART_Routine() interrupt 4  //串口中断子程序
	//电脑向串口发送数据，产生串口接收中断  
{
	if(RI==1)   //产生了串口接收中断
	{   //需要这条语句的原因是发送数据也会产生中断
		P2=~SBUF;  //读入数据  读出的是接收寄存器
		UartSendByte(SBUF);
		RI=0;   //RI置0，清除中断申请
	}
}