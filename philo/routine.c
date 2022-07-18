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

void	printer(t_philo *philo, int id, char *msg)
{
	pthread_mutex_lock(&(philo->args->print));
	if (!philo->args->finish)
		printf("%ld %d %s\n", get_time() - philo->start_time, id, msg);
	pthread_mutex_unlock(&(philo->args->print));
}

void	time_spend(long wait_time, t_args *args)
{
	long	start;
	long	now;

	start = get_time();
	while (!(args->finish))
	{
		now = get_time();
		if ((now - start) >= wait_time)
			break ;
		usleep(10);
	}
}

void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	philo->eat_time = get_time();
	philo->start_time = get_time();
	while (!philo->args->finish)
	{
		eat(philo);
		sleeping(philo);
		think(philo);
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
		eat(philo);
		sleeping(philo);
		think(philo);
	}
	return (0);
}
