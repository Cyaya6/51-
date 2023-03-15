#include <REGX52.H>

sbit LED=P2^0;
void Delay(unsigned char xms)
{
	while(xms--);
}
void main()
{
	
	while(1)
	{
		unsigned char Time,i;
		for(Time=0;Time<100;Time++)
		{
			for(i=0;i<20;Si++)
			{
				LED=0;
				Delay(Time);
				LED=1;
				Delay(100-Time);
			}
		}     
	for(Time=100;Time>0;Time--)
		{
			for(i=0;i<20;i++)
			{
				LED=0;
				Delay(Time);
				LED=1;
				Delay(100-Time);
			}
		}
	}
}
