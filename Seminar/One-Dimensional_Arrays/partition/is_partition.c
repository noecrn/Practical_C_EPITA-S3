#include <stddef.h>

long is_partition(unsigned char a[], size_t len, unsigned char pivot)
{
    int pivot_index = -1;

    for (size_t i = 0; i < len; i++)
    {
        if (a[i] == pivot)
        {
            pivot_index = i;
            break;
        }
    }

    if (pivot_index == -1)
    {
        return -1;
    }

    for (size_t i = 0; i < pivot_index; i++)
    {
        if (a[i] > pivot)
        {
            return -1;
        }
    }

    for (size_t i = pivot_index + 1; i < len; i++)
    {
        if (a[i] < pivot)
        {
            return -1;
        }
    }

    return pivot_index;
}

