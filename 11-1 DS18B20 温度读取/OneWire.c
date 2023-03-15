#include <REGX52.H>

sbit OneWire_DQ=P3^7;


unsigned char OneWire_Init()
{
	unsigned char i;  
	unsigned char AckBit;  
	OneWire_DQ=1;
	OneWire_DQ=0;
	i = 227;while (--i); //延时500us
	
	OneWire_DQ=1; //释放总线
	
	i = 29;while (--i); //延时70us
	AckBit=OneWire_DQ;     //存在的从机会拉低总线  60-240us以响应主机
	i = 227;while (--i); //延时500us
	return AckBit;
}

/**
  * @brief DS18B20发送一位数据
  * @param  
  * @retval 
  */
void OneWire_SendBit(unsigned char Bit)
{
	unsigned char i;  
	OneWire_DQ=0;
	i = 4;while (--i);   //延时10us
	OneWire_DQ=Bit;
	
	i = 22;while (--i);  //延时50us
	OneWire_DQ=1;	
}

unsigned char OneWire_ReceiveBit()
{
	unsigned char i;  
	unsigned char Bit;
	
	OneWire_DQ=0;
	i = 1;while (--i);  //延时5us
	OneWire_DQ=1;
	i = 1;while (--i);  //延时5us
	Bit=OneWire_DQ;
	i = 22;while (--i);  //延时50us
	return Bit;
}

void OneWire_SendByte(unsigned char Byte)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		OneWire_SendBit(Byte&(0x01<<i));
	}
}

unsigned char OneWire_ReceiveByte()
{
	unsigned char i;
	unsigned char Byte=0x00;
	for(i=0;i<8;i++)	
	{
		if(OneWire_ReceiveBit()){Byte|=(0x01<<i);}
	}
	return Byte;
}