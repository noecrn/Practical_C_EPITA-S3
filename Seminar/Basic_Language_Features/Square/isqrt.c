#include "isqrt.h"

unsigned long isqrt(unsigned long n)
{
	unsigned long i = n;

	while ( i * i > n)
		i = i - 1;

	return i;
}
