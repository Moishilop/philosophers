#include "philo.h"

int	ft_inition(t_all *all, int argc, char **argv)
{
	int	i;

	all->flag_death = 0;
	all->argc = argc - 1;
	all->arv = (int *)malloc(sizeof(int) * (argc - 1));
	if (!all->arv)
		return (-1);
	i = 1;
	while (i < argc)
	{	
		all->arv[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	all->mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
	* all->arv[0]);
	if (!all->mutex)
		return (-1);
	all->th = (pthread_t *)malloc(sizeof(pthread_t) * all->arv[0]);
	if (!all->th)
		return (-1);
	if (all->argc != 5)
		all->flag = 0;
	else
		all->flag = 1;
	return (0);
}

int	init_philo_numbers_and_mutex(t_philo *philo, t_all *all)
{
	int	i;

	i = 0;
	while (i < all->arv[0])
	{
		philo[i].i = i + 1;
		philo[i].all = all;
		if (pthread_mutex_init(&all->mutex[i], NULL) != 0)
			return (-1);
		i++;
	}
	if (pthread_mutex_init(&all->print, NULL) != 0)
		return (-1);
	return (0);
}

void	ft_kill_threads(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->arv[0])
	{
		pthread_detach(all->th[i]);
		pthread_mutex_unlock(&all->mutex[i]);
		pthread_mutex_destroy(&all->mutex[i]);
		i++;
	}
	pthread_mutex_unlock(&all->print);
}

int	ft_threads_create(t_all *all, t_philo *philo)
{
	int	i;

	i = 0;
	all->time_start = ft_current_time();
	while (i < all->arv[0])
	{
		if (pthread_create(&all->th[i], NULL, &ft_main, &philo[i]) != 0)
			return (-1);
		i++;
	}
	usleep(30);
	ft_check_death_and_num_of_eating(philo);
	return (0);
}

int	main(int argc, char **argv)
{
	t_philo			*philo;
	t_all			*all;

	if (ft_parse(argc, argv) == 1)
		return (-1);
	philo = (t_philo *)malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	if (!philo)
		return (-1);
	all = (t_all *)malloc(sizeof(t_all) * 1);
	if (!all)
		return (-1);
	if (ft_inition(all, argc, argv) == -1)
		return (-1);
	if (init_philo_numbers_and_mutex(philo, all) == -1)
		return (-1);
	ft_threads_create(all, philo);
	ft_kill_threads(all);
	free(philo);
	return (0);
}
