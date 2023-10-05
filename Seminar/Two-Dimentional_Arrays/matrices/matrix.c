#include <stdio.h>

void print_matrix(char s[], double m[], size_t rows, size_t cols)
{
	printf("%s = \n", s);
	size_t nbElm = rows * cols;
	size_t r = 0;
	for (size_t i = 0; i < nbElm; i++)
	{
		if (r == cols)
		{
			printf("\n");
			r = 0;
		}
		printf("%4g", m[i]);
		r++;
	}
	printf("\n");
}

void transpose(double m[], size_t rows, size_t cols, double r[])
{
    for(size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            r[j * rows + i] = m[i * cols + j];
        }
    }
}

void add(double m1[], double m2[], size_t rows, size_t cols, double r[])
{
        for(size_t i = 0; i < rows; i++)
        {
                for(size_t j = 0; j < cols; j++)
                {
                        size_t index = i * cols + j;
			r[index] = m1[index] + m2[index];
                }
        }
}

void mul(double m1[], double m2[], size_t r1, size_t c1, size_t c2, double r[])
{
	for(size_t i = 0; i < r1; i++)
    	{
	        for (size_t j = 0; j < c2; j++)
        	{
			size_t sum = 0;
			for (size_t k = 0; k < c1; k++)
			{
				size_t index_m1 = i * c1 + k;
				size_t index_m2 = k * c2 + j;
            			sum = sum + m1[index_m1] * m2[index_m2];
			}
			size_t index = i * c1 + j;
			r[index] = sum;
        	}
    	}
}
