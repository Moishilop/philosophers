#include "philo.h"

int	ft_current_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

int	ft_define_time(t_philo *philo)
{
	philo->time = ft_current_time();
	if (philo->all->flag_death == 1)
		return (1);
	return (0);
}

void	ft_extra_f(t_philo *philo)
{
	philo->all->num_of_eating++;
	ft_print(philo, 3);
	philo->last_eating = philo->time;
	my_usleep(philo->all->arv[2]);
	pthread_mutex_unlock(&philo->all->mutex[philo->fork]);
	pthread_mutex_unlock(&philo->all->mutex[philo->i - 1]);
}

int	ft_life_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->all->mutex[philo->i - 1]);
	if (ft_define_time(philo) == 1)
		return (1);
	ft_print(philo, 1);
	if (philo->all->arv[0] == 1)
		return (1);
	pthread_mutex_lock(&philo->all->mutex[philo->fork]);
	if (ft_define_time(philo) == 1)
		return (1);
	ft_print(philo, 1);
	if (ft_define_time(philo) == 1)
		return (1);
	ft_extra_f(philo);
	if (ft_define_time(philo) == 1)
		return (1);
	ft_print(philo, 4);
	my_usleep(philo->all->arv[3]);
	if (ft_define_time(philo) == 1)
		return (1);
	ft_print(philo, 5);
	return (0);
}

void	*ft_main(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if ((philo->i % 2) == 0)
		my_usleep(philo->all->arv[2] / 2);
	philo->all->num_of_eating = 0;
	philo->last_eating = philo->all->time_start;
	if (philo->i == philo->all->arv[0])
		philo->fork = 0;
	else
		philo->fork = philo->i;
	while (1)
	{
		if (ft_life_philo(philo) == 1)
			break ;
	}
	return (0);
}
