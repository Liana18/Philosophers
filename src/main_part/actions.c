
#include "philosophers.h"

void	go_to_sleep(t_philo *philo)
{
	ft_printf("sleeping", philo);
	ft_usleep(philo->time_to_sleep);
}

void	go_to_eat(t_philo *philo)
{
		pthread_mutex_lock((&philo->philo_forks[philo->left_fork]));
		ft_printf("has taken a right fork", philo);
		pthread_mutex_lock((&philo->philo_forks[philo->right_fork]));
		ft_printf("has taken a left fork", philo);
		philo->fix_time = ft_time();
		ft_printf("has eating", philo);
		philo->philo_must_eat++;
		ft_usleep(philo->time_to_eat);
		pthread_mutex_unlock((&philo->philo_forks[philo->left_fork]));
		pthread_mutex_unlock((&philo->philo_forks[philo->right_fork]));

}

