
#include "philosophers.h"

int	error(char *str)
{
	printf("%s\n", str);
	return (1);
}

void	ft_printf(char *str, t_philo *philo)
{
	pthread_mutex_lock(philo->write);
	printf("time -> %lld\t", ft_time() - philo->start_time);
	printf("%d\t", philo->id);
	printf("%s\n", str);
	pthread_mutex_unlock(philo->write);
}