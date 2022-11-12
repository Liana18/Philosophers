/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:13:59 by lter-zak          #+#    #+#             */
/*   Updated: 2022/11/11 19:52:00 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	red(void)
{
	write(1, "\033[1;31m", 7);
}

void	reset(void)
{
	write(1, "\033[0m", 3);
}

int	error(char *str)
{
	char	*str1;
	char	*str2;

	red();
	str1 = "\n\n\n\n\n\n------------------\n\n\n";
	str2 = "\n\n\n------------------\n\n\n\n\n\n";
	write(1, str1, ft_strlen(str1));
	write(1, str, ft_strlen(str));
	write(1, str2, ft_strlen(str2));
	reset();
	return (1);
}
