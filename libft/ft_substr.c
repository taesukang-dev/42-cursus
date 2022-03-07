#include "libft.h"
#include <stdlib.h>

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *temp;

    temp = malloc(sizeof(char) * len);
    while(s[start])
    {
        temp[start] = s[start];
        start++;
    }
    return temp;
}

int main()
{
    char *temp2 = ft_substr("asd", 0, 3);
    return 0;
}