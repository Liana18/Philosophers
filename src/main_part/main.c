/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:37:40 by lter-zak          #+#    #+#             */
/*   Updated: 2022/11/19 12:44:52 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int arg_nb, char **arg_str)
{
	t_philo_gen	*philo_gen;

	philo_gen = malloc(sizeof(t_philo_gen));
	if (arg_nb == 5 || arg_nb == 6)
	{
		if (check_arg(arg_str))
			error("CHECK_ARG_ERROR");
		initialize(philo_gen, arg_str, arg_nb);
		if (init_params(philo_gen))
			error("INIT_PARAMS_ERROR");
	}
	else
		error("main_ERROR");
	//pause();
	return (0);
}
