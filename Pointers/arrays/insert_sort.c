// Insertion using the plain algorithm.
void array_insert(int *begin, int *end, int x)
{
    int* p = end - 1;
    while (p >= begin && *p > x)
    {
        *(p + 1) = *p;
        p--;
    }
    *(p + 1) = x;
}

// Insertion using the binary-search algorithm.
void array_insert_bin(int *begin, int *end, int x)
{
    int *p = begin;
    while (begin < end)
    {
        int *m = begin + (end - begin) / 2;
        if (*m == x)
        {
            return;
        }
        else if (*m < x)
        {
            begin = m + 1;
            p = begin;
        }
        else
        {
            end = m;
        }
    }

    int *c = end;
    while (c > p)
    {
        *c = *(c - 1);
        c--;
    }
    *p = x;
}

// Insertion sort using plain method.
void array_insert_sort(int *begin, int *end)
{
    int i = 1;
    int* p = begin;
    while (i < begin - end)
    {
        int j = i;
        while (j > 0 && *(p + j - 1) > *(p + j))
        {
            swap(p + j - 1, p + j);
            j--;
        }
        i++;
    }
}

// Insertion sort using binary search.
void array_insert_sort_bin(int *begin, int *end)
{
    int i = 1;
    int* p = begin;
    while (i < begin - end)
    {
        int j = i;
        while (j > 0 && *(p + j - 1) > *(p + j))
        {
            swap(p + j - 1, p + j);
            j--;
        }
        i++;
    }
}

int binary_search(int *begin, int *end, int x)
{
    int *p = begin;
    while (begin < end)
    {
        int *m = begin + (end - begin) / 2;
        if (*m == x)
        {
            return m - p;
        }
        else if (*m < x)
        {
            begin = m + 1;
        }
        else
        {
            end = m;
        }
    }
}