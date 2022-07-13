#include "philosophers.h"

void exit_trap(int sig)
{
	printf("error occured\n");
	exit(sig);
}

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
		if ((result > 2147483647 && op == 1) || (result > 2147483648 && op == -1))
			exit_trap(1);
	}
	if (str[i])
		exit_trap(1);
	if (op == -1)
		exit_trap(1);
	return (result * op);
}

int main(int ac, char *av[])
{
	int i;
	int *cmd;

	if (ac == 5 || ac == 6)
	{
		cmd = malloc(sizeof(int) * ac);
		i = 1;
		while (av[i])
		{
			cmd[i - 1] = my_atoi(av[i]);
			i++;
		}
	}
	return 0;
}
