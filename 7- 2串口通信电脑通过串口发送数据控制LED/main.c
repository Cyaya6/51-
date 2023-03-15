#include <REGX52.H>
#include "Delay.h"
#include "Uart.h"

void main()
{
	UartInit(); 
	
	while(1)
	{
		
	}
}

/*串口中断函数模板

void UartRoutine() interrupt 4  //串口中断服务子程序
{
	if(RI==1)
	{

		RI=0;  //中断标志位清零
	}
}
*/
void UartRoutine() interrupt 4  //串口中断服务子程序
{
	if(RI==1)
	{
		P2=~SBUF;
		UartSendByte(SBUF);
		RI=0;  //中断标志位清零
	}
}