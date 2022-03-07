#include "libft.h"

void ft_putstr_fd(char *s, int fd)
{
    write(1, s, fd);
}

int main()
{
    ft_putstr_fd("asd", 3);
    return 0;
}