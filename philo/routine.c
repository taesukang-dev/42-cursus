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

void	time_spend(unsigned long wait_time, t_args *args)
{
	unsigned long	target;

	args = NULL;
	target = wait_time + get_time();
	while (target > get_time())
		usleep(100);
}

void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	philo->eat_time = get_time();
	philo->start_time = get_time();
	if (philo->id % 2)
		usleep(philo->args->eat_time * 1000);
	while (!philo->args->finish)
	{
		eat(philo);
		sleeping(philo);
		think(philo);
		usleep(200);
	}
	return (0);
}
