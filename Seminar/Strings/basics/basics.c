#include <stddef.h>

size_t str_chr(char s[], char c)
{
	size_t len = 0;

	while (s[len] != '\0')
	{
		len++;
	}

	for (size_t i = 0; i < len; i++ )
	{
		if (s[i] == c)
		{
			return i;
		}
	}

	return len;
}

void str_cat(char s1[], char s2[])
{
	int i = 0;
	int j = 0;

	while (s1[i] != '\0')
	{
		i++;
	}

	while (s2[j] != '\0')
	{
		s1[i] = s2[j];
		i++;
		j++;
	}

	s1[i] = '\0';
}

int str_cmp(char s1[], char s2[])
{
	int i = 0;

	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0' && s2[i] == '\0')
		{
			return 0;
		}
		else if (s1[i] == '\0' && s2[i] != '\0')
		{
			return 1;
		}
		else if (s1[i] != '\0' && s2[i] == '\0')
		{
			return -1;
		}

		i++;
	}

	return (s1[i] - s2[i]);
}

unsigned int str_toui(char s[])
{
	int i = 0;
	unsigned int value = 0;

	if (s[0] == '\0')
	{
		return 0;
	}

	if (s[0] == '+' || s[0] == '-')
	{
		i = 1;
	}

	while (s[i] != '\0')
	{
		value = value * 10 + (s[i] - '0');	
		i++;
	}
	
	return value;	
}

void rm_chr(char c, char s[])
{
	int i = 0;
	int j = 0;

	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			s[j] = s[i];
			j++;
		}
		i++;
	}
	s[j] = '\0';
}
