/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkang <tkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:09:02 by tkang             #+#    #+#             */
/*   Updated: 2022/07/18 14:09:03 by tkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_finish(t_philo *philo)
{
	int	i;

	while (!philo->args->finish)
	{
		if (philo->eat_cnt != 0 && philo->eat_cnt == philo->args->eat_cnt)
		{
			philo->args->finish = 1;
			break ;
		}
		i = 0;
		while (i < philo->args->philo_cnt)
		{
			if (get_time() - philo[i].eat_time >= philo->args->die_time)
			{
				printer(philo, i, "is died");
				philo->args->finish = 1;
				break ;
			}
			i++;
		}
	}
}

void	start_processing(t_philo *philo, t_args *args)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (i < args->philo_cnt)
	{
		if (i % 2)
			res = pthread_create(&(philo[i].p_thread), \
				NULL, routine_odd, &philo[i]);
		else
			res = pthread_create(&(philo[i].p_thread), \
				NULL, routine, &philo[i]);
		usleep(200);
		i++;
	}
	check_finish(philo);
	i = 0;
	while (i < args->philo_cnt)
	{
		pthread_join(philo[i].p_thread, NULL);
		i++;
	}
}

void	all_free(pthread_mutex_t *fork, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->args->philo_cnt)
	{
		pthread_mutex_destroy(&(fork[i]));
		i++;
	}
	free(fork);
	free(philo);
	pthread_mutex_destroy(&(philo->args->print));
}

int	main(int ac, char *av[])
{
	t_args	args;
	t_philo	*philo;

	if (ac != 5 && ac != 6)
		exit_trap(1);
	init_args(&args, ac, av);
	init_philo(&philo, &args);
	start_processing(philo, &args);
	all_free(args.fork, philo);
	return (0);
}
