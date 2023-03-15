#include <REGX52.H>
#include "Delay.h"
#include "Matrix_Led.h"
//流动的动画数据
unsigned char code AmationData[]={   //不可更改 放到Flash中 就不占用RAM内存了
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xFF,0x08,0x08,0x08,0x08,0xFF,0x00,0x3F,
	0x25,0x25,0x3D,0x00,0xFF,0x01,0x01,0x01,
	0x00,0xFF,0x01,0x01,0x00,0x3F,0x21,0x21,
	0x3F,0x00,0x3F,0x21,0x21,0x3F,0x00,0x3D,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};
void main()
{
	unsigned char i,offset=1,count=0;
	Matrix_Init();
	
	while(1)
	{
		//笑脸
//		MatrixLed_ShowColumn(0x3C,0);
//		MatrixLed_ShowColumn(0x42,1);
//		MatrixLed_ShowColumn(0xA9,2);
//		MatrixLed_ShowColumn(0x85,3);
//		MatrixLed_ShowColumn(0x85,4);
//		MatrixLed_ShowColumn(0xA9,5);
//		MatrixLed_ShowColumn(0x42,6);
//		MatrixLed_ShowColumn(0x3C,7);
		
		//爱心
//		MatrixLed_ShowColumn(0x38,0);
//		MatrixLed_ShowColumn(0x7C,1);
//		MatrixLed_ShowColumn(0x3E,2);
//		MatrixLed_ShowColumn(0x1F,3);
//		MatrixLed_ShowColumn(0x1F,4);
//		MatrixLed_ShowColumn(0x3E,5);
//		MatrixLed_ShowColumn(0x7C,6);
//		MatrixLed_ShowColumn(0x38,7);
		
		//显示动画
		for(i=0;i<8;i++)
		{
			MatrixLed_ShowColumn(AmationData[i+offset],i);
		}
		count++;
		if(count>20)   //延时
		{
			count=0;
			offset++;  //偏移量加一
		}
		if(offset>40)  //设置
		{
			offset=0;
		}
	}
}
