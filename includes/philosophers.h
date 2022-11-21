/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 19:30:44 by lter-zak          #+#    #+#             */
/*   Updated: 2022/11/20 18:16:58 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo		t_philo;
typedef struct s_philo_gen	t_philo_gen;

struct s_philo
{
	t_philo_gen	*philo_gen;
	int			id;
	int			left_fork;
	int			right_fork;
	int			p_num;
	int			time_die;
	int			time_sleep;
	int			time_eat;
	int			ph_must_eat;
	long long	born_time;
	long long	fix_time;
	pthread_t	tr_id;
};

struct s_philo_gen
{
	int				philo_num;
	int				time_die;
	int				time_sleep;
	int				time_eat;
	int				philo_must_eat;
	int				check_die;
	long long int	start_time;
	pthread_mutex_t	sleep;
	pthread_mutex_t	eating;
	pthread_mutex_t	smt;
	pthread_mutex_t	*forks;
	t_philo			*philo;
};

void				check_die(t_philo_gen *philo_gen, t_philo *philo);
void				initialize(t_philo_gen *philo_arg, char **argv, int argc);
int					check_arg(char **arg_str);
int					ft_strlen(char *str);
int					ft_atoi(char *str);
int					error(char *str);
int					init_params(t_philo_gen *philo_gen);
void				ft_usleep(unsigned long long tm);
unsigned long long	ft_time(void);
int				ft_printf(char *str, int id, t_philo_gen *philo_gen);
#endif
