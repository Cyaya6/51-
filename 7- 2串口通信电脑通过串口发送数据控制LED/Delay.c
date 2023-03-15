//延时
void Delay(unsigned char xms)		//@12.000MHz
{
	while(xms--)
	{
		unsigned char i, j;
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
	}
}
