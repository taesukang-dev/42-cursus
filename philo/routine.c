/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkang <tkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:09:16 by tkang             #+#    #+#             */
/*   Updated: 2022/07/18 14:09:16 by tkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void time_spend(long wait_time, t_args *args)
{
	long start;
	long now;

	start = get_time();
	while(!(args->finish))
	{
		now = get_time();
		if ((now - start) >= wait_time)
			break ;
		usleep(10);
	}
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&(philo->args->fork[philo->left]));
	printf("%ld %d has taken a fork\n", \
		get_time() - philo->start_time, philo->id);
	if (philo->args->philo_cnt != 1)
	{
		pthread_mutex_lock(&(philo->args->fork[philo->right]));
		printf("%ld %d has taken a fork\n", \
			get_time() - philo->start_time, philo->id);
		printf("%ld %d is eating\n", get_time() - philo->start_time, philo->id);
		philo->eat_time = get_time();
		philo->eat_cnt += 1;
		time_spend(philo->args->eat_time, philo->args);
		pthread_mutex_unlock(&(philo->args->fork[philo->right]));
	}
	pthread_mutex_unlock(&(philo->args->fork[philo->left]));
}

void	eat_odd(t_philo *philo)
{
	pthread_mutex_lock(&(philo->args->fork[philo->right]));
	printf("%ld %d has taken a fork\n", \
		get_time() - philo->start_time, philo->id);
	if (philo->args->philo_cnt != 1)
	{
		pthread_mutex_lock(&(philo->args->fork[philo->left]));
		printf("%ld %d has taken a fork\n", \
			get_time() - philo->start_time, philo->id);
		printf("%ld %d is eating\n", get_time() - philo->start_time, philo->id);
		philo->eat_time = get_time();
		philo->eat_cnt += 1;
		time_spend(philo->args->eat_time, philo->args);
		pthread_mutex_unlock(&(philo->args->fork[philo->left]));
	}
	pthread_mutex_unlock(&(philo->args->fork[philo->right]));
}	

void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	philo->eat_time = get_time();
	philo->start_time = get_time();
	while (!philo->args->finish)
	{
		if (get_time() - philo->eat_time >= philo->args->die_time)
		{
			printf("%ld %d is died\n", \
				get_time() - philo->start_time, philo->id);
			philo->args->finish = 1;
			break ;
		}
		if (philo->eat_cnt != 0 && philo->eat_cnt == philo->args->eat_cnt)
			break ;
		eat(philo);
		printf("%ld %d is sleeping\n", \
			get_time() - philo->start_time, philo->id);
		time_spend(philo->args->sleep_time, philo->args);
		printf("%ld %d is thinking\n", \
			get_time() - philo->start_time, philo->id);
	}
	return (0);
}

void	*routine_odd(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	philo->eat_time = get_time();
	philo->start_time = get_time();
	while (!philo->args->finish)
	{
		if (get_time() - philo->eat_time >= philo->args->die_time)
		{
			printf("%ld %d is died\n", \
				get_time() - philo->start_time, philo->id);
			philo->args->finish = 1;
			break ;
		}
		if (philo->eat_cnt != 0 && philo->eat_cnt == philo->args->eat_cnt)
			break ;
		eat_odd(philo);
		printf("%ld %d is sleeping\n", \
			get_time() - philo->start_time, philo->id);
		time_spend(philo->args->sleep_time, philo->args);
		printf("%ld %d is thinking\n", \
			get_time() - philo->start_time, philo->id);
	}
	return (0);
}
