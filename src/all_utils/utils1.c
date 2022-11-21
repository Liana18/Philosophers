/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:16:52 by lter-zak          #+#    #+#             */
/*   Updated: 2022/11/20 18:20:31 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_strlen(char *str)
{
	int	c;

	c = 0;
	while (str[c])
		c++;
	return (c);
}

int	ft_atoi(char *str)
{
	int	i;
	int	num;
	int	min;

	min = 1;
	num = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			min = min * -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * min);
}

int	ft_printf(char *str, int id, t_philo_gen *philo_gen)
{
	pthread_mutex_lock(&philo_gen->smt);
	if (philo_gen->check_die)
	{
		printf("%lld ,", ft_time() - philo_gen->start_time);
		printf("%d ,", id);
		printf("%s\n", str);
	}
	else
		{
			printf("%lld ,", ft_time() - philo_gen->start_time);
			printf("%d -> ", id);
			printf("%s\n", str);
			return (0);
		}
	pthread_mutex_lock(&philo_gen->smt);
	return (0);
}
