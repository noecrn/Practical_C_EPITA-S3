#include <stdio.h>
#include "digit_count.h"
#include "power_of_two.h"

int main() {
    unsigned long result;
    unsigned long num;
    int i;
    printf("digit_count(0) = 1\n");

    for (i = 0; i <= 63; i++)
    {
	    num = power_of_two(i);
	    result = digit_count(num);
	    printf("digit_count(%ld) = %lu\n", num, result);
    }

    return 0;
}
