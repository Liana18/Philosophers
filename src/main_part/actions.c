/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 19:27:47 by lter-zak          #+#    #+#             */
/*   Updated: 2022/11/26 20:25:49 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	go_to_sleep(t_philo *philo)
{
	ft_printf("☾ sleeping ☾", philo);
	ft_usleep(philo->time_to_sleep);
}

void	go_to_eat(t_philo *philo)
{
	pthread_mutex_lock((&philo->philo_forks[philo->left_fork]));
	ft_printf("⍦ has taken a right fork ⍦", philo);
	pthread_mutex_lock((&philo->philo_forks[philo->right_fork]));
	ft_printf("⍦ has taken a left fork ⍦", philo);
	philo->fix_time = ft_time();
	ft_printf("⁌ has eating ⁍", philo);
	philo->philo_must_eat++;
	ft_usleep(philo->time_to_eat);
	pthread_mutex_unlock((&philo->philo_forks[philo->left_fork]));
	pthread_mutex_unlock((&philo->philo_forks[philo->right_fork]));
}

void	*ft_thread_hendler(void *ph)
{
	t_philo	*philo;

	philo = (t_philo *)ph;
	philo->fix_time = ft_time();
	if (philo->id % 2 == 0)
		ft_usleep(philo->time_to_eat);
	while (1)
	{
		go_to_eat(philo);
		go_to_sleep(philo);
		ft_printf("☺︎ is thinking ☺︎", philo);
	}
}

void	the_end(t_philo_gen *philo_gen)
{
	int	i;

	i = 0;
	while (i < philo_gen->num_of_philo)
		pthread_mutex_destroy(&philo_gen->forks_gen[i++]);
	pthread_mutex_destroy(philo_gen->write);
}
