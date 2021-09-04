#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <signal.h>
# include <semaphore.h>

# define GREEN "\x1b[32m"
# define BLUE "\x1b[34m"
# define RED "\x1b[31m"
# define YEL "\x1b[33m"
# define NONE "\x1b[0m"

typedef struct s_all_bon
{
	pid_t			*pids;
	sem_t			*sem;
	sem_t			*s_print;
	int				*arv;
	int				argc;
	int				flag;
	int				without_food;
	int				i;
	int				time_start;
	int				num_of_eat;
	int				last_eating;
	int				flag_death;
	pthread_t		*th;
}					t_all_bon;

int		ft_current_time(void);
int		ft_parse(int argc, char **argv);
int		ft_is_digit(char c);
int		ft_time(int time_start);
int		ft_atoi(char *str);
int		ft_strlen(char *s);
void	*ft_main(void *arg);
void	my_usleep(int milsec);
int		ft_living(t_all_bon *all_bon, int i);
int		ft_init(t_all_bon *all_bon, int argc, char **argv);
void	print_mes(int flag, t_all_bon *all_bon, int i);
void	*ft_monitor(void *arg);
int		ft_main_liv(t_all_bon *all_bon, int i);
void	one_philo(t_all_bon *all_bon);
void	ft_eating(t_all_bon *all_bon, int i);
void	ft_thinking(t_all_bon *all_bon, int i);
void	ft_post(t_all_bon *all_bon, int i);

#endif