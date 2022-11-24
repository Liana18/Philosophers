#include "philosophers.h"

long long	ft_time(void)
{
	struct timeval	time;
	long long		ms;

	gettimeofday(&time, NULL);
	ms = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (ms);
}

void ft_usleep(long long tm)
{
	long long time;

	time = ft_time();
	while (ft_time() - time <= tm)
			usleep (100);
}