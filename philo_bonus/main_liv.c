#include "philo.h"

int	ft_living(t_all_bon *all_bon, int i)
{
	all_bon->last_eating = all_bon->time_start;
	all_bon->i = i + 1;
	all_bon->num_of_eat = 0;
	if (i % 2 != 0)
		my_usleep(all_bon->arv[2] / 2);
	pthread_create(&all_bon->th[i], NULL, &ft_monitor, all_bon);
	pthread_detach(all_bon->th[i]);
	return (ft_main_liv(all_bon, i));
}

void	*ft_monitor(void *arg)
{
	t_all_bon	*all_bon;

	all_bon = (t_all_bon *)arg;
	while (all_bon->flag_death != 1)
	{
		one_philo(all_bon);
		all_bon->without_food = ft_current_time() - all_bon->last_eating;
		if (all_bon->without_food > all_bon->arv[1])
		{
			sem_wait(all_bon->s_print);
			printf("%d %d %sdied%s\n", ft_current_time() - \
			all_bon->time_start, all_bon->i, RED, NONE);
			all_bon->flag_death = 1;
			exit(1);
		}
		if (all_bon->argc == 5 && all_bon->num_of_eat >= all_bon->arv[4])
		{
			all_bon->flag = 1;
			exit(0);
		}
		usleep(100);
	}
	return (0);
}

int	ft_main_liv(t_all_bon *all_bon, int i)
{
	while (1)
	{
		if (all_bon->flag_death == 1)
			return (1);
		if (all_bon->flag == 1)
			return (0);
		sem_wait(all_bon->sem);
		print_mes(1, all_bon, i);
		if (all_bon->arv[0] == 1 || all_bon->flag_death == 1)
			return (1);
		sem_wait(all_bon->sem);
		print_mes(1, all_bon, i);
		if (all_bon->flag_death == 1)
			return (1);
		ft_eating(all_bon, i);
		if (all_bon->flag == 1)
			return (1);
		ft_post(all_bon, 2);
		if (all_bon->flag_death == 1)
			return (1);
		ft_thinking(all_bon, i);
		if (all_bon->flag_death == 1)
			return (1);
		print_mes(4, all_bon, i);
	}
}
