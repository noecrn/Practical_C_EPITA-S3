#include <stdio.h>
#include "pascal.h"

// Prints Pascal's Triangle.
// tr: triangle to print
// len: length of the triangle.
void print_triangle(unsigned int tr[][MAX_LEN], size_t len)
{
	for (size_t i = 0; i < len; i++)
	{
        	tr[i][0] = 1;
    	}

    	for (size_t i = 1; i < len; i++)
    	{
        	tr[i][0] = 1;
        	for (size_t j = 1; j <= i; j++)
        	{
            		tr[i][j] = tr[i - 1][j - 1] + tr[i - 1][j];
        	}
    	}
}

// Generates Pascal's Triangle.
// tr: triangle to generate.
// len: length of the triangle.
void pascal_triangle(unsigned int tr[][MAX_LEN], size_t len)
{
	unsigned int max_value = tr[len - 1][len / 2];
    	int width = 1;

    	while (max_value > 0)
    	{
        	max_value /= 10;
        	width++;
    	}

    	for (size_t i = 0; i < len; i++)
    	{
        	for (size_t j = 0; j <= i; j++)
        	{
            		if (tr[i][j] != 0)
            		{
                		printf("%*u ", width, tr[i][j]);
            		}
        	}
        	printf("\n");
    	}
}
