/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 19:32:36 by lter-zak          #+#    #+#             */
/*   Updated: 2022/11/28 17:12:34 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_eat(t_philo_gen *philo_gen)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (i < philo_gen->num_of_philo)
	{
		if (philo_gen->philo[i].philo_must_eat >= philo_gen->philo_must_eat)
			count++;
		i++;
	}
	return (count);
}

int	check_die(t_philo_gen *philo_gen, t_philo *philo)
{
	int	i;

	i = 0;
	while (1)
	{
		i = 0;
		if (philo_gen->philo_must_eat != 0
			&& check_eat(philo_gen) == philo_gen->num_of_philo)
		{
			ft_printf("OK\n", philo);
			return (0);
		}
		while (i < philo_gen->num_of_philo)
		{
			if (ft_time() - philo[i].fix_time > philo_gen->time_to_die)
			{
				ft_printf("☠︎ has DIED ☠︎", &philo_gen->philo[i]);
				return (1);
			}
			i++;
		}
	}
	return (0);
}
