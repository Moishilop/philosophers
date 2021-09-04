#include "philo.h"

int	ft_current_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

void	one_philo(t_all_bon *all_bon)
{
	if (all_bon->arv[0] == 1)
	{
		usleep(30);
		sem_wait(all_bon->s_print);
		printf("%d %d %sdied%s\n", all_bon->arv[1], all_bon->i, RED, NONE);
		all_bon->flag_death = 1;
		exit(1);
	}
}

void	ft_eating(t_all_bon *all_bon, int i)
{
	all_bon->last_eating = ft_current_time();
	print_mes(2, all_bon, i);
	my_usleep(all_bon->arv[2]);
	all_bon->num_of_eat++;
}

void	ft_thinking(t_all_bon *all_bon, int i)
{
	print_mes(3, all_bon, i);
	my_usleep(all_bon->arv[3]);
}

void	ft_post(t_all_bon *all_bon, int i)
{
	while (i > 0)
	{
		sem_post(all_bon->sem);
		i--;
	}
}
