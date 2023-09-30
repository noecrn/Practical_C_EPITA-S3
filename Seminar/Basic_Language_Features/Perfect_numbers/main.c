#include <stdio.h>
#include "is_perfect_number.h"

int main()
{
	for ( unsigned long i = 1; i < 100000; i++ )
	{
		unsigned long result = is_perfect_number(i);
		if ( result == 1 )
		{
			printf( "%ld\n", i );
		}
	}
	return 0;
}
