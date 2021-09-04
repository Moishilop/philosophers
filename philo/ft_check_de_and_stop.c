#include "philo.h"

int	one_philo(t_philo *philo, int i)
{
	philo->all->flag_death = 1;
	pthread_mutex_lock(&philo->all->print);
	printf("%d %d %sdied%s\n", philo->all->arv[1], \
	i, RED, NONE);
	return (0);
}

int	dead_philo(t_philo *philo, int i)
{
	philo->all->flag_death = 1;
	pthread_mutex_lock(&philo->all->print);
	printf("%d %d %sdied%s\n", ft_current_time() - \
	philo[i].all->time_start, philo[i].i, RED, NONE);
	return (0);
}

int	check_num_of_eating(t_philo *philo)
{
	if (philo->all->num_of_eating >= \
	philo->all->arv[4] * philo->all->arv[0])
	{	
		philo->all->flag_death = 1;
		return (1);
	}
	return (0);
}

int	ft_check_death_and_num_of_eating(t_philo *philo)
{
	int	i;

	while (philo->all->flag_death != 1)
	{
		usleep(100);
		i = 0;
		while (i < philo->all->arv[0])
		{
			if (philo->all->flag == 1)
			{
				if (check_num_of_eating(philo) == 1)
					break ;
			}
			philo[i].without_food = ft_current_time() - \
			philo[i].last_eating;
			if (philo->all->arv[0] == 1)
				return (one_philo(philo, philo[i].i));
			if (philo[i].without_food <= philo[i].all->arv[1])
				i++;
			else
				return (dead_philo(philo, i));
		}
	}
	return (0);
}
