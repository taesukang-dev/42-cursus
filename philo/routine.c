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
		usleep(philo->args->eat_time);
		philo->eat_time = get_time();
		philo->eat_cnt += 1;
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
		usleep(philo->args->eat_time);
		philo->eat_time = get_time();
		philo->eat_cnt += 1;
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
	while (1)
	{
		if (get_time() - philo->eat_time >= philo->args->die_time)
			break ;
		if (philo->eat_cnt != 0 && philo->eat_cnt == philo->args->eat_cnt)
			break ;
		eat(philo);
		printf("%ld %d is sleeping\n", \
			get_time() - philo->start_time, philo->id);
		usleep(philo->args->sleep_time);
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
	while (1)
	{
		if (get_time() - philo->eat_time >= philo->args->die_time)
			break ;
		if (philo->eat_cnt != 0 && philo->eat_cnt == philo->args->eat_cnt)
			break ;
		eat_odd(philo);
		printf("%ld %d is sleeping\n", \
			get_time() - philo->start_time, philo->id);
		usleep(philo->args->sleep_time);
		printf("%ld %d is thinking\n", \
			get_time() - philo->start_time, philo->id);
	}
	return (0);
}
