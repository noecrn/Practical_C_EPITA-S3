#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include "divisor_sum.h"

int main( int argc, char** argv )
{
	unsigned long param = strtoul(argv[1], NULL, 10);
	unsigned long num = divisor_sum(param);
	
	if( param == 0 || argc != 2)
	{
		errx(1, "Error");
	}
	
	printf( "divisor_sum(%ld) = %lu\n", param, num );

	return 0;
}
