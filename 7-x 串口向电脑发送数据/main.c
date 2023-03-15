#include <REGX52.H>
#include "Delay.h"
#include "Uart.h"
unsigned char sec;

void main()
{
	UartInit();
	
	while(1)
	{
		UartSendByte(sec);
		sec++;
		Delay(1000);
	}
}
