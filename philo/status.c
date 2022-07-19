/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkang <tkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 20:48:35 by tkang             #+#    #+#             */
/*   Updated: 2022/07/18 20:48:36 by tkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&(philo->args->fork[philo->left]));
	printer(philo, philo->id, "has taken a fork");
	if (philo->args->philo_cnt != 1)
	{
		pthread_mutex_lock(&(philo->args->fork[philo->right]));
		printer(philo, philo->id, "has taken a fork");
		printer(philo, philo->id, "is eating");
		time_spend(philo->args->eat_time, philo->args);
		philo->eat_time = get_time();
		philo->eat_cnt += 1;
		pthread_mutex_unlock(&(philo->args->fork[philo->right]));
	}
	pthread_mutex_unlock(&(philo->args->fork[philo->left]));
}

void	sleeping(t_philo *philo)
{
	printer(philo, philo->id, "is sleeping");
	time_spend(philo->args->sleep_time, philo->args);
}

void	think(t_philo *philo)
{
	printer(philo, philo->id, "is thinking");
}
