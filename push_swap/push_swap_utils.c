#include "push_swap.h"

int	my_atoi(const char *str)
{
	size_t	i;
	long	result;
	long	op;

	i = 0;
	result = 0;
	op = 1;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		op = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ('0' <= str[i] && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	if (str[i])
		exit_trap();
	if (result > 2147483647 && op == 1 || result > 2147483648 && op == -1)
		exit_trap();
	return (result * op);
}

void	two_d_free(char **str)
{
	size_t	i;

	i = 0;
	while(str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	init_doubly(t_DoublyList **dList, char *argv[], int argc)
{
	size_t	i;
	size_t	j;
	char **temp;

	*dList = create_doubly_list();
	i = 0;
	while(++i < argc)
	{
		temp = ft_split(argv[i], ' ');
		j = 0;
		if (!temp[j])
			exit_trap();
		while(temp[j])
		{
			add_left_dl_element(*dList, my_atoi(temp[j]));
			j++;
		}
		two_d_free(temp);
	}
}

void	exit_trap()
{
	write(2, "Error\n", 6);
	exit(1);
}
