# include <stdio.h>

unsigned long sum_of_divisors(unsigned long n, size_t *count)
{
    unsigned long divisor = 0;
    *count = 0;

    for (unsigned long i = 0; i < n; i++)
    {
        if (n % i == 0)
        {
            divisor += i;
            (*count)++;
        }
    }
    return divisor;
}

int main()
{
    unsigned long x;
    unsigned long sum;
    size_t count;

    x = 28;
    sum = sum_of_divisors(x, &count);
    printf("x = %lu\n", x);
    printf("sum   = %lu\n", sum);
    printf("count = %zu\n\n", count);

    x = 100;
    sum = sum_of_divisors(x, &count);
    printf("x = %lu\n", x);
    printf("sum   = %lu\n", sum);
    printf("count = %zu\n", count);
}