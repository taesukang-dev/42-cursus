/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkang <tkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:09:10 by tkang             #+#    #+#             */
/*   Updated: 2022/07/18 14:09:11 by tkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	exit_trap(int sig)
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
		if ((result > 2147483647 && op == 1) \
			|| (result > 2147483648 && op == -1))
			exit_trap(1);
	}
	if (str[i])
		exit_trap(1);
	return (result * op);
}

long	get_time(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (now.tv_sec * 1000 + now.tv_usec / 1000);
}

void	init_args(t_args *args, int ac, char *av[])
{
	int	i;

	memset(args, 0, sizeof(t_args));
	args->philo_cnt = my_atoi(av[1]);
	args->fork = malloc(sizeof(pthread_mutex_t) * (args->philo_cnt));
	if (!args->fork)
		exit_trap(1);
	i = 0;
	while (i < args->philo_cnt)
	{
		if (pthread_mutex_init(&(args->fork[i]), NULL))
			exit_trap(1);
		i++;
	}
	if (pthread_mutex_init(&(args->print), NULL))
		exit_trap(1);
	args->die_time = my_atoi(av[2]);
	args->eat_time = my_atoi(av[3]);
	args->sleep_time = my_atoi(av[4]);
	if (ac == 6)
		args->eat_cnt = my_atoi(av[5]);
	args->finish = 0;
	args->finished_eat_cnt = 0;
}

void	init_philo(t_philo **philo, t_args *args)
{
	int	i;
	int	num_phil;

	num_phil = args->philo_cnt;
	*philo = malloc(sizeof(t_philo) * args->philo_cnt);
	if (!*philo)
		exit_trap(1);
	i = 0;
	while (i < num_phil)
	{
		(*philo)[i].args = args;
		(*philo)[i].id = i;
		(*philo)[i].left = i;
		(*philo)[i].right = (i + 1) % num_phil;
		(*philo)[i].eat_time = 0;
		(*philo)[i].eat_cnt = 0;
		(*philo)[i].finished_eat = 0;
		i++;
	}
}
