#include "philo.h"

void	ft_print(t_philo *philo, int flag)
{
	pthread_mutex_lock(&philo->all->print);
	if (flag == 1)
	{
		printf("%d %d has taken a fork\n", \
		ft_current_time() - philo->all->time_start, philo->i);
	}
	if (flag == 3)
	{
		printf("%d %d %sis eating%s\n", philo->time - \
		philo->all->time_start, philo->i, GREEN, NONE);
	}
	if (flag == 4)
	{
		printf("%d %d %sis sleeping%s\n", philo->time \
		- philo->all->time_start, philo->i, YEL, NONE);
	}
	if (flag == 5)
	{
		printf("%d %d %sis thinking%s\n", philo->time \
		- philo->all->time_start, philo->i, BLUE, NONE);
	}
	pthread_mutex_unlock(&philo->all->print);
}
