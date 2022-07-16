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

void init_philo(t_philo **philo, t_args *args)
{
	int i;
	int num_phil;

	num_phil = args->philo_cnt;
	*philo = malloc(sizeof(t_philo) * args->philo_cnt);
	i = 0;
	while(i < num_phil)
	{
		(*philo)[i].args = args;
		(*philo)[i].id = i;
		(*philo)[i].status = THINKING;
		(*philo)[i].left = i;
		(*philo)[i].right = (i + 1) % num_phil;
		(*philo)[i].eat_time = 0;
		(*philo)[i].eat_cnt = 0;
		i++;
	}
}

void *test(void *data)
{
	t_philo	philo;

	philo = *((t_philo *)data);
	printf("%ld\n", philo.eat_time);
	printf("%d\n", philo.args->philo_cnt);
	return 0;
}

void start_processing(t_philo *philo, t_args *args)
{
	int i;

	i = 0;
	while(i < args->philo_cnt)
	{
		philo[i].eat_time = get_time();
		pthread_create(&(philo[i].p_thread), NULL, test, &philo[i]);
		i++;
	}
	i = 0;
	while(i < args->philo_cnt)
	{
		pthread_join(philo[i].p_thread, NULL);
		i++;
	}
}

int main(int ac, char *av[])
{
	int i;
	int *cmd;
	t_args args;
	t_philo *philo;
	if (ac != 5 && ac != 6)
		exit_trap(1);
	init_args(&args, ac, av);
	init_philo(&philo, &args);
	start_processing(philo, &args);
	// i = 0;
	// while (i < args.philo_cnt)
	// {
	// 	pthread_create(&philo[i].philo, NULL, 함수, (void *)&i);
	// 	i++;
	// }
	// i = 0;
	// while (i < args.philo_cnt)
	// {
	// 	pthread_join(philo[i].philo, NULL);
	// 	i++;
	// }

	return 0;
}
