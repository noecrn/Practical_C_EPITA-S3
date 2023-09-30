#include "power_of_two.h"
#include <math.h>

unsigned long power_of_two(unsigned long n)
{
	if ( n == 0 )
	{
		return 1;
	}
	else
	{
		return pow( 2, n );
	}
}
