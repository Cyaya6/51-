#include <REGX52.H>
#include "I2C.h"

#define AT24C02_ADDRESS_W 0xA0  //从机地址
#define AT24C02_ADDRESS_R 0xA1  

/** 
  * @brief AT24C02写入一个字节  I2C发送一位数据
  * @param  WordAdress 要写入的字节地址 
	* @param  Data 要写入的数据
  * @retval 无
  */
void AT24C02_WriteByte(unsigned char WordAdress,Data)
{
	//unsigned char Ack;
	I2C_Start();
	I2C_SendByte(AT24C02_ADDRESS_W);
	I2C_ReceiveACK();
	//Ack=I2C_ReceiveACK();  测试应答是否应答
	//if(Ack==0)P2=0x00;
	I2C_SendByte(WordAdress);
	I2C_ReceiveACK();
	
	I2C_SendByte(Data);
	I2C_ReceiveACK();
	
	I2C_Stop(); 
	
}
/**
	* @brief AT24C02读出一个字节的地址  
  * @param  WordAdress 要写入的字节地址  
  * @retval 读出的数据
  */
unsigned char AT24C02_ReadByte(unsigned char WordAdress)
{
	unsigned char Data;
	I2C_Start();
	I2C_SendByte(AT24C02_ADDRESS_W);
	I2C_ReceiveACK();
	
	I2C_SendByte(WordAdress);
	I2C_ReceiveACK();
	
	I2C_Start();
	I2C_SendByte(AT24C02_ADDRESS_R);  //I2C_SendByte(AT24C02_ADDRESS|0x01);
	I2C_ReceiveACK();
	
	Data=I2C_ReceiveByte();
	I2C_SendAck(1);
	I2C_Stop();
	return Data;
}	