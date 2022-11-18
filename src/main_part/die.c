/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:09:39 by lter-zak          #+#    #+#             */
/*   Updated: 2022/11/18 14:46:57 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_die(t_philo_gen *philo_gen, t_philo *philo)
{
	unsigned long long  die_time;
	int	i;

	i = 0;
	die_time = (unsigned long long)philo_gen->time_die;
	while (!(philo_gen->check_die))
	{
		i = 0;
		while (i < philo_gen->philo_num)
		{
			if (ft_time() - philo->fix_time > die_time)
			{
				// printf("ft_time -> %lld\n",ft_time() );
				// printf("start__time -> %lld\n",philo_gen->start_time );
				printf("time -> %lld ,%d has DIED\n",
				ft_time() - philo_gen->start_time, philo->id);
				philo_gen->check_die = 1;
			}
			i++;
		}
		//if (philo_gen->check_die)
		//	break ;
	}
	return (0);
}
