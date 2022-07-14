#include "philo.h"

void init_args(t_args *args, int ac, char *av[])
{
	memset(args, 0, sizeof(t_args));
	args->fork = my_atoi(av[1]);
	args->die_time = my_atoi(av[2]);
	args->eat_time = my_atoi(av[3]);
	args->sleep_time = my_atoi(av[4]);
	if (ac == 6)
		args->eat_cnt = my_atoi(av[5]);
}

int main(int ac, char *av[])
{
	int i;
	int *cmd;
	t_args args;

	if (ac != 5 && ac != 6)
		exit_trap(1);
	init_args(&args, ac, av);
	printf("%d\n", args.fork);
	printf("%d\n", args.die_time);
	printf("%d\n", args.eat_time);
	printf("%d\n", args.sleep_time);
	printf("%d\n", args.eat_cnt);
	return 0;
}
