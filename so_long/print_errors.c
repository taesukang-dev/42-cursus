#include "so_long.h"

void	print_errors(char *str)
{
	write(2, str, ft_strlen(str));
	exit(1);
}
