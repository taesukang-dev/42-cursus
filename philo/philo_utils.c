#include "philo.h"

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
		exit_trap(1);
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
	return (result * op);
}