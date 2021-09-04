#include "philo.h"

void	my_usleep(int milsec)
{
	int	time_start;

	time_start = ft_current_time();
	while (ft_current_time() - time_start < milsec)
		usleep(50);
}
