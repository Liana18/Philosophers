/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creator.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:36:56 by lter-zak          #+#    #+#             */
/*   Updated: 2022/11/15 14:12:41 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	go_take_fork(t_philo )
{
	//pthread_mutex_lock
	got_eat();
	//pthread_mutex_unalock
}

void *ft_thread_hendler(void *philo)
{
	t_philo_gen *philo_gen;
	t_philo		*philo;
	
	philo_gen =(t_philo*)philo;
	while (1)
	{
		go_take_fork();
		go_to_sleep();
		
	}
	return(0);
}

int	create_philo(t_philo *philo, int philo_num)
{
	int i;

	i = 0;
	while (i < philo_num)
	{
		philo[i].ph_time = ft_time();
		if (!(pthread_create(&(philo[i].tr_id), NULL,ft_thread_hendler, ((void *)&philo[i]))))
				i++;
		else
			return (1);
	}
	return (0);
}

int	create_mutex(t_philo_gen	*philo_gen)
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
	if (create_philo(philo_gen->philo, philo_gen->philo_num))
		return (1);
		philo_gen->start_time = ft_time();
	return (0);
}
	