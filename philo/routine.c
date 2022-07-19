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
	if (philo->id % 2)
		usleep(1000);
	else
		usleep(500);
	while (!philo->args->finish)
	{
		if (philo->args->eat_cnt && \
			!philo->finished_eat && philo->eat_cnt == philo->args->eat_cnt)
		{
			philo->finished_eat = 1;
			philo->args->finished_eat_cnt += 1;
			break ;
		}
		eat(philo);
		sleeping(philo);
		think(philo);
	}
	return (0);
}
