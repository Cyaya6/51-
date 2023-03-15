#include <REGX52.H>

sbit I2C_SCL=P2^1;
sbit I2C_SDA=P2^0;

void I2C_Start()
{
	I2C_SDA=1;
	I2C_SCL=1;  //SCL为高电平
	
	
	I2C_SDA=0;  //SDA出现下降沿
	I2C_SCL=0;
}


void I2C_Stop()
{
	I2C_SDA=0;
	I2C_SCL=1;
	
	I2C_SDA=1;
	I2C_SCL=0;
}

void I2C_SendByte(unsigned char byte)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		I2C_SDA=byte&(0x80>>i);   //高位到低位 逐位进行读取
		I2C_SCL=1;  //产生一个下降沿  读取数据
		I2C_SCL=0;
	}
}

unsigned char I2C_ReceiveByte()
{
	unsigned char i,byte=0x00;
	I2C_SDA=1;   //释放总线
	
	for(i=0;i<8;i++)
	{
		I2C_SCL=1;   //SDA的数据不再变化  控制权已经交给了从机  已经接收到了byte的最高位并且开始读取
		if(I2C_SDA){byte|=(0x80>>i);}  //如果SDA为1 说明要接受的byte的最高位为1
		I2C_SCL=0;
	}

	return byte;
}


void I2C_SendAck(unsigned char AckBit)
{
	I2C_SDA=AckBit;
	I2C_SCL=1;
	I2C_SCL=0;
}

unsigned char I2C_ReceiveAck()
{
	unsigned char AckBit;
	I2C_SDA=1;   //主机释放对SDA的控制  这样从机才能够控制SDA为1或0
	I2C_SCL=1;
	AckBit=I2C_SDA;   //从机控制SDA
	I2C_SCL=0;
	return AckBit;
}