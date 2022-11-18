/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creator.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:36:56 by lter-zak          #+#    #+#             */
/*   Updated: 2022/11/17 20:27:19 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	got_eat(t_philo *philo, t_philo_gen *philo_gen)
{
	long long int time;
	while(ft_time)
	//if (philo_gen->philo_must_eat != )
}

int	go_take_fork(t_philo *philo, t_philo_gen *philo_gen)
{
	// printf("philo->right_fork == %d\n\n", philo->right_fork);
	// printf("philo->left_fork == %d\n\n", philo->left_fork);
	pthread_mutex_lock(&(philo_gen->forks[philo->right_fork]));
	printf("time -> %lld ,%d has taken a right fork", ft_time() - philo_gen->start_time, philo->id);
	pthread_mutex_lock(&(philo_gen->forks[philo->left_fork]));
	printf("time -> %lld ,%d has taken a left fork", ft_time() - philo_gen->start_time, philo->id);
	got_eat(philo, philo_gen);
	pthread_mutex_unlock(&(philo_gen->forks[philo->right_fork]));
	pthread_mutex_unlock(&(philo_gen->forks[philo->left_fork]));
	return (0);
}

void *ft_thread_hendler(void *ph)
{
	t_philo_gen *philo_g;
	t_philo		*philo; 
	
	philo =(t_philo*)ph;
	philo_g = philo->philo_gen;
	while ( 1  )//cheack_ddi
	{
		//printf("right_fork == %d\n\n", philo->right_fork);
		//printf("left_fork == %d\n\n", philo->left_fork);
		go_take_fork(philo ,philo_g);
		//fix the time;
		//go_to_sleep();
		//printf("Is thinking")
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

	index = 0;

	philo_gen->philo = malloc(sizeof(t_philo) * philo_gen->philo_num);
	while (index < philo_gen->philo_num)
	{

		philo_gen->philo[index].id = index;
		philo_gen->philo[index].left_fork = index;
		philo_gen->philo[index].right_fork = (index + 1) % philo_gen->philo_num;
		philo_gen->philo[index].p_num = philo_gen->philo_num;
		philo_gen->philo[index].t_die = philo_gen->time_die;
		philo_gen->philo[index].t_eat = philo_gen->time_eat;
		philo_gen->philo[index].t_sleep = philo_gen->time_sleep;
		if (philo_gen->philo_must_eat != 0)
			philo_gen->philo[index].ph_must_eat = philo_gen->philo_must_eat;
		else
			philo_gen->philo[index].ph_must_eat = 0;
		index++;

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
		// printf("right_fork == %d\n\n",philo_gen->philo[0].right_fork);
		// printf("left_fork == %d\n\n", philo_gen->philo[0].left_fork);
		philo_gen->start_time = ft_time();
	return (0);
}
	