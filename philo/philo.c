#include "philo.h"

void *routine(void *data)
{
	t_philo	*philo;
	long	now;

	philo = (t_philo *)data;
	while (1)
	{
		if (get_time() - philo->eat_time > philo->args->die_time)
			break ;
		if (philo->eat_cnt == philo->args->eat_cnt)
			break ;
		pthread_mutex_lock(&(philo->args->fork[philo->left]));
		if (philo->args->philo_cnt != 1)
		{
			printf("%ld %d has taken a fork\n", get_time() - philo->start_time, philo->id);
			pthread_mutex_lock(&(philo->args->fork[philo->right]));
			printf("%ld %d has taken a fork\n", get_time() - philo->start_time, philo->id);
			printf("%ld %d is eating\n",get_time() - philo->start_time, philo->id);
			usleep(philo->args->eat_time / 1000); 
			philo->eat_time = get_time();
			philo->eat_cnt += 1;
			pthread_mutex_unlock(&(philo->args->fork[philo->right]));
		}
		pthread_mutex_unlock(&(philo->args->fork[philo->left]));
		printf("%ld %d is sleeping\n", get_time() - philo->start_time, philo->id);
		usleep(philo->args->sleep_time / 1000);
		printf("%ld %d is thinking\n", get_time() - philo->start_time, philo->id);
	}
	return 0;
}

void *routine_odd(void *data)
{
	t_philo	*philo;
	long	now;

	philo = (t_philo *)data;
	while (1)
	{
		if (get_time() - philo->eat_time > philo->args->die_time)
			break ;
		if (philo->eat_cnt == philo->args->eat_cnt)
			break ;
		pthread_mutex_lock(&(philo->args->fork[philo->right]));
		
		if (philo->args->philo_cnt != 1)
		{
			printf("%ld %d has taken a fork\n", get_time() - philo->start_time, philo->id);
			pthread_mutex_lock(&(philo->args->fork[philo->left]));	
			printf("%ld %d has taken a fork\n", get_time() - philo->start_time, philo->id);
			printf("%ld %d is eating\n",get_time() - philo->start_time, philo->id);
			usleep(philo->args->eat_time / 1000); 
			philo->eat_time = get_time();
			philo->eat_cnt += 1;
			pthread_mutex_unlock(&(philo->args->fork[philo->left]));
		}
		pthread_mutex_unlock(&(philo->args->fork[philo->right]));
		printf("%ld %d is sleeping\n", get_time() - philo->start_time, philo->id);
		usleep(philo->args->sleep_time / 1000);
		printf("%ld %d is thinking\n", get_time() - philo->start_time, philo->id);
	}
	return 0;
}

void start_processing(t_philo *philo, t_args *args)
{
	int i;

	i = 0;
	while(i < args->philo_cnt)
	{
		philo[i].eat_time = get_time();
		philo[i].start_time = get_time();
		if (i % 2)
			pthread_create(&(philo[i].p_thread), NULL, routine_odd, &philo[i]);
		else
			pthread_create(&(philo[i].p_thread), NULL, routine, &philo[i]);
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
	int		i;
	int		*cmd;
	t_args	args;
	t_philo	*philo;
	
	if (ac != 5 && ac != 6)
		exit_trap(1);
	init_args(&args, ac, av);
	init_philo(&philo, &args);
	start_processing(philo, &args);
	return 0;
}
