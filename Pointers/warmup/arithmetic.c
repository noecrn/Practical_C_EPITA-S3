# include <stdio.h>

int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
int *begin = arr;
int *end = arr + 10;
int copy[10] = { 0, };

#define PRINT(a) \
for (size_t i = 0; i < size; i++)\
    if (i != size - 1)\
        printf("%2i, ", *(a + i));\
    else\
        printf("%2i]\n", *(a + i))\

// Swap the contents of two variables.
void swap(int* a, int* b)
{
    int _a = *a;
    *a = *b;
    *b = _a;
}

// Return the sum of the array from 'begin' to 'end'.
int array_sum(int *begin, int *end)
{
    int sum = 0;
    for (int* p = begin; p < end; p++)
    {
        sum += *p;
    }
    return sum;
}

// Reverse the array from 'begin' to 'end'.
void array_reverse(int *begin, int *end)
{
    while (begin < end) {
        swap(begin, end - 1);
        begin++;
        end--;
    }
}

// Copy the array from 'begin' to 'end' into 'dst'.
// The dst array must be large enough.
// The two arrays do not overlap.
void array_copy(int *dst, int *begin, int *end)
{
    for (int* p = begin, *q = dst; p < end; p++, q++)
    {
        *q = *p;
    }
}

// Shift the array from 'begin' to 'end' by one position to the right.
// The leftmost value will not change.
// The rightmost value will be lost.
// For instance:
// - Before: 1 2 3 4 5
// - After:  1 1 2 3 4
void array_rshift(int *begin, int *end)
{
    for (int* p = end - 1; p > begin; p--)
    {
        *p = *(p - 1);
    }
}

int main()
{
    size_t size = end - begin;

    printf("Initial arr  = [");
    PRINT(arr);

    int sum = array_sum(begin, end);
    printf("sum          = %2i\n", sum);

    array_reverse(begin, end);
    printf("Reversed arr = [");
    PRINT(arr);

    array_copy(copy, begin, end);
    printf("Copy         = [");
    PRINT(copy);

    array_rshift(begin, end);
    array_rshift(begin, end);
    array_rshift(begin, end);
    printf("Shifted arr  = [");
    PRINT(arr);
}