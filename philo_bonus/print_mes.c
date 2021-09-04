#include "philo.h"

int	ft_init(t_all_bon *all_bon, int argc, char **argv)
{
	int	i;

	all_bon->argc = argc - 1;
	all_bon->arv = (int *)malloc(sizeof(int) * (argc - 1));
	if (!all_bon->arv)
		return (-1);
	i = 1;
	while (i < argc)
	{	
		all_bon->arv[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	return (0);
}

void	print_mes(int flag, t_all_bon *all_bon, int i)
{
	char	*str;

	if (flag == 1)
		str = "has taken a fork\n";
	if (flag == 2)
		str = "is eating\n";
	if (flag == 3)
		str = "is thinking\n";
	if (flag == 4)
		str = "is sleeping\n";
	sem_wait(all_bon->s_print);
	printf("%d %d %s", ft_current_time() - all_bon->time_start, i + 1, str);
	sem_post(all_bon->s_print);
}
