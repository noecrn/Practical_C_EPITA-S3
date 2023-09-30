#include <stdio.h>
#include "fibo.h"

int main() {
    unsigned long result;
    int i;

    for (i = 0; i <= 10; i++)
    {
	    result = fibo(i);
	    printf("fibo(%d) = %lu\n", i, result);
    }
    printf("...\n");
    for (i = 81; i <= 90; i++)
    {
	    result = fibo(i);
	    printf("fibo(%d) = %lu\n", i, result);
    }

    return 0;
}
