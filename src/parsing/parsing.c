
#include "philosophers.h"

int	check_argv_rul(t_philo_gen *philo_gen)
{
	if (philo_gen->time_to_eat < 60 || philo_gen->time_to_die < 60
		|| philo_gen->time_to_sleep < 60 || philo_gen->num_of_philo > 200)
	{
		printf("You don't have the right to discuss this case\n");
		return (1);
	}
	if (philo_gen->num_of_philo == 0)
		return (1);
	return (0);
}

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