#include <stdio.h>
#include "isqrt.h"

int main() {
    unsigned long result;
    int i;

    for (i = 0; i <= 200; i += 8)
    {
	    result = isqrt(i);
	    printf("isqrt(%d) = %lu\n", i, result);
    }

    return 0;
}
