#include "libft.h"

size_t check_size(char const *s, char c)
{
    size_t  i;
    size_t  res;

    i = 0;
    res = 0;
    while(s[i])
    {
        if (s[i] != c)
        {
            res++;
            while(s[i] && s[i] != c)
                i++;
        }
        else
            i++;
    }
    return res;
}

char    **ft_split(char const *s, char c)
{
    char    **buf;
    size_t  s_size;
    size_t  i;
    size_t  j;
    size_t  k;

    s_size = check_size(s, c);
    printf("%zu", s_size);
    if (!s)
        return (NULL);
    buf = (char **)malloc(sizeof(char *) * s_size + 1);
    if (!buf)
        return (NULL);
    i = 0;
    while(s[i])
    {
        j = 0;
        if(s[i] != c)
        {
            k = 0;
            while(s[i] != c)
            {
                buf[j][k] = s[i];
                k++;
                i++;
            }
            buf[j][k] = '\0';
            j++;
        }
        i++;
    }
    buf[j] = 0;
    return buf;
}

int main()
{
    char **temp;
    temp = ft_split("asdasd", 's');
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; temp[i]; j++)
            printf("%c", temp[i][j]);
    }
    return 0;
}