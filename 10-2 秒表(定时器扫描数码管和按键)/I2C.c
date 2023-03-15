#include <REGX52.H>

sbit I2C_SCL=P2^1;
sbit I2C_SDA=P2^0;

/**
  * @brief I2C开始函数 发送开始信号
  * @param  无 
  * @retval 无
  */
void I2C_Start()
{
	I2C_SDA=1;
  I2C_SCL=1;
	
	I2C_SDA=0;
  I2C_SCL=0;
}

/**
  * @brief I2C停止函数 发送停止信号
  * @param  无
  * @retval 无
  */
void I2C_Stop()
{
	I2C_SDA=0;
	
  I2C_SCL=1;
	I2C_SDA=1; 	
}

/**
  * @brief I2C发送一个字节  用于发送一个八位数据
  * @param  byte 要发送的八位数据
  * @retval 无
  */
void I2C_SendByte(unsigned char byte)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
	I2C_SDA=byte&(0x80>>i);
	I2C_SCL=1;
	I2C_SCL=0;
	}
	
}

/**
  * @brief I2C接收函数 用于接收一个八位数据
  * @param  无
  * @retval 返回接收道德八位数据
  */
unsigned char I2C_ReceiveByte()
{
	unsigned char i,byte=0x00;
	I2C_SDA=1;
	
	for(i=0;i<8;i++)
	{
		I2C_SCL=1;
	if(I2C_SDA==1)
	{
		byte|=(0x80>>i);
	}
	I2C_SCL=0;
	}
	
	return byte;
}

/**
  * @brief I2C发送应答函数 发送一个ACK信号
	* @param  ACK 应答位 0为应答，1为非应答
  * @retval 无
  */
void I2C_SendAck(unsigned char ACK)
{
	I2C_SDA=ACK;
	
	I2C_SCL=1;
	I2C_SCL=0;
}

/**
  * @brief I2C接收应答
  * @param  无
  * @retval 接收到的应答位
  */
unsigned char I2C_ReceiveACK()
{
	unsigned char AckBit;
	
	I2C_SDA=1;
	I2C_SCL=1;	
	AckBit=I2C_SDA;
	I2C_SCL=0;
	return AckBit;
}