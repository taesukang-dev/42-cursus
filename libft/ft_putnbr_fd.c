#include "libft.h"

void ft_putchar_fd(char c, int fd)
{
    write(1, &c, fd);
}

int main()
{
    ft_putchar_fd('a', 1);

    return 0;
}