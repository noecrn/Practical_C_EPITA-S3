#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void exit_help()
{
    char help[] = "main: Usage: str1 str2";

    errx(EXIT_FAILURE, "%s", help);
}

void substring(char* str, char* arg)
{
    int i = 0;
    int j = 0;
    int arg_len = 0;
    int str_len = 0;
    bool flag = false;

    while (arg[arg_len] != '\0')
    {
        arg_len++;
    }

    while (str[str_len] != '\0')
    {
        str_len++;
    }

    while (str[i] != '\0')
    {
        if (str[i] == arg[j])
        {
            flag = true;
            j++;
        }
        if (str[i] != arg[j] && flag)
        {
            flag = false;
            j = 0;
        }
        if (arg[j] == '\0' && flag)
        {
        
        }
        i++;
    }

    str[str_len] = '\n';
    str[str_len] = '\0';

    for (int k = str_len; k < str_len * 2; k++)
    {
        str[str_len * 2 - arg_len] = '^';
    }
}
