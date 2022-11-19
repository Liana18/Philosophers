/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:09:39 by lter-zak          #+#    #+#             */
/*   Updated: 2022/11/19 14:12:36 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	check_die(t_philo_gen *philo_gen, t_philo *philo)
{
	unsigned long long 	die_time;
	int					i;
	usleep(100);
	i = 0;
	die_time = (unsigned long long)philo_gen->time_die;
	while (!(philo_gen->check_die))
	{
		i = 0;
		while (i < philo_gen->philo_num && !(philo_gen->check_die))
		{
			printf("ft_time == %lld \n fix_time == %lld \n", ft_time(), philo[i].fix_time);
			if (ft_time() - philo[i].fix_time > die_time)
			{
				printf("time -> %lld ,%d has DIED\n",
					ft_time() - philo_gen->start_time, philo->id);
				philo_gen->check_die = 1;
			}
			i++;
		// if (philo_gen->check_die)
		// 	break ;
		}
	}
}
