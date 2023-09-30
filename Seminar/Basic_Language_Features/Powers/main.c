#include <stdio.h>
#include "power_of_two.h"

int main() {
    unsigned long result;
    int i;

    for (i = 0; i <= 63; i++)
    {
	    result = power_of_two(i);
	    printf("power_of_two(%d) = %lu\n", i, result);
    }

    return 0;
}
