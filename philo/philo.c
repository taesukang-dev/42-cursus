#include "philo.h"

void init_args(t_args *args, int ac, char *av[])
{
	int i;

	memset(args, 0, sizeof(t_args));
	args->philo_cnt = my_atoi(av[1]);
	args->fork = malloc(sizeof(pthread_mutex_t) * (args->philo_cnt));
	i = 0;
	while(i < args->philo_cnt)
	{
		pthread_mutex_init(&(args->fork[i]), NULL);
		i++;
	}
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
	struct timeval mytime;

	// if (ac != 5 && ac != 6)
	// 	exit_trap(1);
	// init_args(&args, ac, av);
	// printf("%d\n", args.fork);
	// printf("%d\n", args.die_time);
	// printf("%d\n", args.eat_time);
	// printf("%d\n", args.sleep_time);
	// printf("%d\n", args.eat_cnt);

	gettimeofday(&mytime, NULL);
	printf("%ld %ld", mytime.tv_sec, mytime.tv_usec / 1000);
	return 0;
}
