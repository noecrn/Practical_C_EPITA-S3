#include "digit_count.h"
#include <math.h>

unsigned long digit_count(unsigned long n)
{
	unsigned long i = n;
	unsigned long count = 0;

	if ( n == 0 )
	{
		count = 1;
	}
	else
	{
		while ( i != 0 )
		{
			i /= 10;
			count++;
		}
	}

	return count;
}
