#include "divisor_sum.h"
#include <math.h>

unsigned long divisor_sum(unsigned long n)
{
	unsigned long num = 0;

	for ( unsigned long i = 1; i < n; i++ )
	{
		if ( n % i == 0 )
		{
			num += i;
		}
	}
	
	return num;
}
