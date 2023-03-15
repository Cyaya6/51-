//延时
void Delay(unsigned char xms)		//@11.0592MHz
{
	unsigned char i, j;

	while(xms--)
	{
		//_nop_();
	i = 2;
	j = 236;
	do
	{
		while (--j);
	} while (--i);
	}
}
