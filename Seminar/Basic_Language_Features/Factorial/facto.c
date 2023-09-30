#include "facto.h"

unsigned long facto(unsigned long n)
{
	if (n == 0 || n == 1)
	{
		return 1;
	}
	else
	{
		return n * facto(n - 1);
	}
}
