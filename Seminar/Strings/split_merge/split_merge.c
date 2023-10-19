#include <stddef.h>
#include "split_merge.h"

void split(char s[], char words[][MAX_CHAR])
{
	int i = 0;
	int j = 0;
	int k = 0;

	while (s[i] != '\0')
	{
		while (s[i] == ' ')
		{
			i++;
		}

		while (s[i] != ' ' && s[i] != '\0')
		{
			words[k][j] = s[i];
			j++;
			i++;
		}

		words[k][j] = '\0';
		k++;
		j = 0;

		while (s[i] == ' ')
		{
			i++;
		}
	}
	words[k][j] = '\0';
}

void merge(char s[], size_t argc, char** argv)
{
	s[0] = '\0';
	size_t len = 0;

	for (size_t i = 2; i < argc; i++)
	{
		for (size_t j = 0; argv[i][j] != '\0'; j++)
		{
			s[len] = argv[i][j];
			len++;
		}
	}

	s[len] = '\0';
}
