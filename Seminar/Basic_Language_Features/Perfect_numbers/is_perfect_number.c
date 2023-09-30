#include "is_perfect_number.h"
#include "divisor_sum.h"

unsigned long is_perfect_number(unsigned long n)
{
	if( divisor_sum(n) == n )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
