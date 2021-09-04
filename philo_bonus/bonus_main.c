#include "philo.h"

int	main_part(t_all_bon *all_bon)
{
	int	i;
	int	status;

	if (all_bon->argc == 5)
	{
		i = 0;
		while (i < all_bon->arv[0])
		{
			waitpid(-1, &status, 0);
			if (WEXITSTATUS(status) == 1)
				break ;
			i++;
		}
	}
	else
		waitpid(-1, &status, 0);
	i = 0;
	while (i < all_bon->arv[0])
	{
		kill(all_bon->pids[i], SIGKILL);
		i++;
	}
	sem_close(all_bon->sem);
	sem_close(all_bon->s_print);
	return (0);
}

int	main(int argc, char **argv)
{
	t_all_bon	*all_bon;
	int			i;

	i = 0;
	if (ft_parse(argc, argv) == 1)
		return (-1);
	all_bon = malloc(sizeof(t_all_bon));
	ft_init(all_bon, argc, argv);
	all_bon->pids = (pid_t *)malloc(sizeof(pid_t) * (all_bon->arv[0]));
	all_bon->th = (pthread_t *)malloc(sizeof(pthread_t) * all_bon->arv[0]);
	all_bon->flag_death = 0;
	all_bon->sem = sem_open("semathore", O_CREAT, 0666, all_bon->arv[0]);
	all_bon->s_print = sem_open("sem_print", O_CREAT, 0666, 1);
	sem_unlink("semathore");
	sem_unlink("sem_print");
	all_bon->flag = 0;
	all_bon->time_start = ft_current_time();
	while (i < all_bon->arv[0])
	{
		all_bon->pids[i] = fork();
		if (all_bon->pids[i] == 0)
			return (ft_living(all_bon, i));
		i++;
	}
	return (main_part(all_bon));
}
