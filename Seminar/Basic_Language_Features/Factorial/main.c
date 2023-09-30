#include <stdio.h>
#include "facto.h"

int main() {
    unsigned long result;
    int i;

    for (i = 0; i <= 20; i++) {
        result = facto(i);
        printf("facto(%d) = %lu\n", i, result);
    }

    return 0;
}
