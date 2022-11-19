/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creator.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:36:56 by lter-zak          #+#    #+#             */
/*   Updated: 2022/11/19 14:21:48 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	got_eat(t_philo *philo, t_philo_gen *philo_gen)
{
	unsigned long long int eat_time;
	eat_time = (unsigned long long)philo_gen->time_eat;
	pthread_mutex_lock(&(philo_gen->eating));
	printf("time -> %lld ,%d has eating\n", ft_time() - philo_gen->start_time, philo->id);
	philo->fix_time = ft_time();
	printf("fix_time1 = %lld\n\n", philo->fix_time);
	pthread_mutex_unlock(&(philo_gen->eating));
	printf("check_die ==> %d\n", philo_gen->check_die);
		long long int time_now;

		time_now = ft_time();
	while(!(philo_gen->check_die))
	{
		if (eat_time  <= ft_time() - time_now)
				break ;	
	}
	return (0);
}

int	go_take_fork(t_philo *philo, t_philo_gen *philo_gen)
{
while (!(philo_gen->check_die))
{
	pthread_mutex_lock(&(philo_gen->forks[philo->right_fork]));
	printf("time -> %lld ,%d has taken a right fork\n", ft_time() - philo_gen->start_time, philo->id);
	pthread_mutex_lock(&(philo_gen->forks[philo->left_fork]));
	printf("time -> %lld ,%d has taken a left fork\n", ft_time() - philo_gen->start_time, philo->id);
	got_eat(philo, philo_gen);
	printf("time -> %lld ,%d thinking\n", ft_time() - philo_gen->start_time, philo->id);
	pthread_mutex_unlock(&(philo_gen->forks[philo->right_fork]));
	pthread_mutex_unlock(&(philo_gen->forks[philo->left_fork]));
}
	return (0);
}

void *ft_thread_hendler(void *ph)
{
	t_philo_gen *philo_g;
	t_philo		*philo; 
	
	philo =(t_philo*)ph;
	philo_g = philo->philo_gen;
	if (philo->id % 2)
		usleep(10000);
	while (!(philo_g->check_die))//cheack_ddi
	{	
		go_take_fork(philo ,philo_g);
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
		philo[i].born_time = ft_time();
	
		if (!(pthread_create(&(philo[i].tr_id), NULL,ft_thread_hendler, ((void *)&philo[i]))))
				i++;
		else
			return (1);
	}
	usleep(1000);
	printf("fix tikmmmmmmmm == %lld\n", philo[i].fix_time);
	check_die(philo->philo_gen, philo);
	return (0);
}

int	create_mutex(t_philo_gen	*philo_gen)
{
	int	index;

	index = 0;
	if(pthread_mutex_init(&philo_gen->eating, NULL))
			return (1);
	philo_gen->forks = malloc(sizeof(pthread_mutex_t) * philo_gen->philo_num);
	if (!(philo_gen->forks))
		return (1);
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
	philo_gen->check_die = 0;
	while (index < philo_gen->philo_num)
	{
		philo_gen->philo[index].id = index;
		philo_gen->philo[index].left_fork = index;
		philo_gen->philo[index].right_fork = (index + 1) % philo_gen->philo_num;
		philo_gen->philo[index].p_num = philo_gen->philo_num;
		philo_gen->philo[index].time_die = philo_gen->time_die;
		philo_gen->philo[index].time_eat = philo_gen->time_eat;
		philo_gen->philo[index].time_sleep = philo_gen->time_sleep;
		philo_gen->philo[index].fix_time = 0;
		if (philo_gen->philo_must_eat != 0)
			philo_gen->philo[index].ph_must_eat = philo_gen->philo_must_eat;
		else
			philo_gen->philo[index].ph_must_eat = 0;
		philo_gen->philo[index].philo_gen = philo_gen;
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
	philo_gen->start_time = ft_time();
	 if (create_philo(philo_gen->philo, philo_gen->philo_num))
	 	return (1);
	//printf("haaa\n");
	//check_die(philo_gen, philo_gen->philo);
	return (0);
}
	