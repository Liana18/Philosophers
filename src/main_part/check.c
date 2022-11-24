
#include "philosophers.h"

int check_eat(t_philo_gen *philo_gen)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < philo_gen->num_of_philo)
	{
		if (philo_gen->philo[i].philo_must_eat >= philo_gen->philo_must_eat)
			count++;
		i++;
	}
		//printf("smt == %d\n", philo_gen->philo[i].philo_must_eat);
	if (count + 1 == philo_gen->num_of_philo)
		return (1);
	return (0);
}

int	check_die(t_philo_gen *philo_gen, t_philo *philo)
{
	int	i;

	i = 0;
	while (1)
	{
		i = 0;
		if (check_eat(philo_gen))
		{
			printf("OK\n");
			return (0);
		}
		while (i < philo_gen->num_of_philo)
		{
			if (ft_time() - philo[i].fix_time > philo_gen->time_to_die)
			{
				ft_printf("has DIED", &philo_gen->philo[i]);
				return (1);
			}
			i++;
		}
	}
	return (0);
}
