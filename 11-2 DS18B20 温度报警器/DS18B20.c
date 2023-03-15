#include <REGX52.H>
#include "OneWire.h"
#include "LCD1602.h"

//DS18B20指令
#define DS18B20_SKIP_ROW  				0xCC
#define DS18B20_CONVERT_T 				0x44
#define DS18B20_READ_SCRATCHPAD 	0xBE
/**
  * @brief  DS18B20开始温度变换
  * @param  无
  * @retval 无
  */
void DS18B20_ConvertT()
{
	OneWire_Init();
	OneWire_SendByte(DS18B20_SKIP_ROW);
	OneWire_SendByte(DS18B20_CONVERT_T);
}

/**
  * @brief  DS18B20读取温度
  * @param  无
  * @retval 温度数值
  */
float DS18B20_ReadT()
{
	unsigned char TLSB,TMSB;
	int temp;
	float T;
	OneWire_Init();
	OneWire_SendByte(DS18B20_SKIP_ROW);
	OneWire_SendByte(DS18B20_READ_SCRATCHPAD);
	TLSB=OneWire_ReceiveByte();
	TMSB=OneWire_ReceiveByte();
//	LCD_ShowBinNum(1,1,TMSB,8);
//	LCD_ShowBinNum(1,9,TLSB,8);
	temp=(TMSB<<8)|TLSB;
	T=temp/16.0;
	
	return T;
}