#include <REGX52.H>
#include "Delay.h"
#include "NixieTube.h"

void main()
{
	while(1)
	{
		NixieTube(5,4);
		NixieTube(6,3);
		NixieTube(7,2);
		NixieTube(8,1);
	}
}