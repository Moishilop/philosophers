#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <semaphore.h>

# define GREEN "\x1b[32m"
# define BLUE "\x1b[34m"
# define RED "\x1b[31m"
# define YEL "\x1b[33m"
# define NONE  "\x1b[0m"

typedef struct s_all
{
	int				argc;
	int				time_start;
	int				*arv;
	int				flag;
	int				flag_death;
	int				num_of_eating;
	pthread_t		*th;
	pthread_t		check_deaft;
	pthread_mutex_t	print;
	pthread_mutex_t	*mutex;
}					t_all;

typedef struct s_philo
{
	int				i;
	int				time;
	int				fork;
	int				without_food;
	int				last_eating;
	t_all			*all;
}					t_philo;

typedef struct s_all_bon
{
	pid_t			*pids;
	sem_t			sem;
	int				*arv;
	int				argc;
	int				i;
}					t_all_bon;

int		ft_current_time(void);
int		ft_parse(int argc, char **argv);
int		ft_is_digit(char c);
int		ft_time(int time_start);
int		ft_atoi(char *str);
int		ft_threads_create(t_all *all, t_philo *philo);
int		ft_strlen(char *s);
int		ft_check_death_and_num_of_eating(t_philo *philo);
void	*ft_main(void *arg);
void	ft_print(t_philo *philo, int flag);
void	my_usleep(int milsec);

#endif