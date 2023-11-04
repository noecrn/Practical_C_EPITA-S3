#include <assert.h>
#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "helper.h"
#include "insert_sort.h"

#define DEFAULT_SIZE 16

int main(int argc, char *argv[])
{
    size_t len = DEFAULT_SIZE;

    srandom(time(NULL));
    if (argc > 1)
        len = strtoul(argv[1], NULL, 10);

    int *array = calloc(len, sizeof (int));
    int *copy = calloc(len, sizeof (int));
    int *begin = array, *end = array + len;

    // Fill the array with sorted values.
    array_sorted_fill(begin, end);

    // Test the algorithms on a presorted array.
    // -----------------------------------------------------------------------
    array_print(begin, end);
    bench_sort(begin, end, array_insert_sort, "insert_sort (sorted)");
    array_print(begin, end);
    bench_sort(begin, end, array_insert_sort_bin, "insert_sort_bin (sorted)");
    array_print(begin, end);

    // Example test cases for array_is_sorted
    int sorted_array[] = {1, 2, 3, 4, 5};
    int unsorted_array[] = {5, 3, 2, 4, 1};

    if (array_is_sorted(sorted_array, sorted_array + 5)) {
        printf("sorted_array is sorted\n");
    } else {
        printf("sorted_array is not sorted\n");
    }

    if (array_is_sorted(unsorted_array, unsorted_array + 5)) {
        printf("unsorted_array is sorted\n");
    } else {
        printf("unsorted_array is not sorted\n");
    }

    // Fill the array with random values
    // and copy it in order to test the algorithms on the same array.
    // -----------------------------------------------------------------------
    array_random_fill(begin, end);
    memcpy(copy, begin, len * sizeof (int));

    // Test the algorithms on a random array.
    // -----------------------------------------------------------------------
    array_print(begin, end);
    bench_sort(begin, end, array_insert_sort, "insert_sort (random)");
    array_print(begin, end);
    memcpy(begin, copy, len * sizeof (int));
    array_print(begin, end);
    bench_sort(begin, end, array_insert_sort_bin, "insert_sort_bin (random)");
    array_print(begin, end);

    // free memory
    free(array);
    free(copy);

    return 0;
}