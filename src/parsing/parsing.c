/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 19:34:02 by lter-zak          #+#    #+#             */
/*   Updated: 2022/11/18 15:16:42 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_arg(char **arg_str)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (arg_str[i])
	{
		j = 0;
		while (arg_str[i][j])
		{
			if ((arg_str[i][j] >= '0' && arg_str[i][j] <= '9'))
				j++;
			else
				if ((arg_str[i][j] == '+') && (arg_str[i][j + 1] >= '0'
					&& arg_str[i][j + 1] <= '9'))
					j++;
			else
				return (1);
		}
			i++;
	}
	return (0);
}

void	initialize(t_philo_gen *philo_arg, char **argv, int argc)
{
	int	i;

	i = 1;
	philo_arg->philo_num = ft_atoi(argv[1]);
	philo_arg->time_die = ft_atoi(argv[2]);
	philo_arg->time_eat = ft_atoi(argv[3]);
	philo_arg->time_sleep = ft_atoi(argv[4]);
	philo_arg->philo_must_eat = 0;
	philo_arg->check_die = 0;
	philo_arg->start_time = 0;
	if (argc == 6)
		philo_arg->philo_must_eat = ft_atoi(argv[5]);
}
