/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 19:27:40 by lter-zak          #+#    #+#             */
/*   Updated: 2022/11/26 19:27:42 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	initialize(t_philo_gen *philo_gen, char **argv, int argc)
{
	philo_gen->num_of_philo = ft_atoi(argv[1]);
	philo_gen->time_to_die = ft_atoi(argv[2]);
	philo_gen->time_to_eat = ft_atoi(argv[3]);
	philo_gen->time_to_sleep = ft_atoi(argv[4]);
	philo_gen->philo_must_eat = 0;
	if (argc == 6)
	{
		philo_gen->philo_must_eat = ft_atoi(argv[5]);
		if (philo_gen->philo_must_eat == 0)
			return (1);
	}
	return (0);
}
