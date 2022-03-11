#include "libft.h"
#include <stdio.h>

int ft_strlen(char const *s)
{
    int i;

    i = 0;
    while(s[i])
    {
        i++;
    }
    return i;
}

char *ft_strjoin(char const *s1, char const *s2)
{
    char *temp;
    int s1_len;
    int s2_len;
    int i;

    s1_len = ft_strlen(s1);
    s2_len = ft_strlen(s2);
    temp = malloc(sizeof(char) * (s1_len + s2_len) + 1);
    i = 0;
    while(s1[i])
    {
        temp[i] = s1[i];
        i++;
    }
    i = 0;
    while(s2[i])
    {
        temp[s1_len] = s2[i];
        i++;
        s1_len++;
    }
    return temp;
}

