/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creator.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:36:56 by lter-zak          #+#    #+#             */
/*   Updated: 2022/11/12 14:04:24 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	create_mutex(t_philo_gen *philo_gen)
{
	int	index;
	index = 0;
	philo_gen->forks = malloc(sizeof(pthread_mutex_t) * philo_gen->philo_num);
	while (index < philo_gen->philo_num)
	{ 
		if(pthread_mutex_init(&philo_gen->forks[index], NULL))
			return (1);
		index++;			
	}
	return (0);
}

int	init_philo(t_philo_gen *philo_gen)
{
	int index;
	t_philo temp;

	index = 0;

	philo_gen->philo = malloc(sizeof(t_philo) * philo_gen->philo_num);
	while (index < philo_gen->philo_num)
	{
		temp.id = index;
		temp.left_fork = index;
		temp.right_fork = (index + 1) % philo_gen->philo_num;
		temp.p_num = philo_gen->philo_num;
		temp.t_die = philo_gen->time_die;
		temp.t_eat = philo_gen->time_eat;
		temp.t_sleep = philo_gen->time_sleep;
		if (philo_gen->philo_must_eat != 0)
			temp.ph_must_eat = philo_gen->philo_must_eat;
		else
			temp.ph_must_eat = 0;
		index++;
		philo_gen->philo[index] = temp;

	}
	
	return (0);                                                                                                                                                                                                                
}

int	init_params(t_philo_gen *philo_gen)
{
	if (create_mutex(philo_gen))
		return (1);
	if (init_philo(philo_gen))
		return (1);
	// if (create_philo(philo_gen))
	// 	return (1);
		philo_gen->start_time = ft_time();
		printf("st_time = %lld", philo_gen->start_time);
	return (0);
}
	