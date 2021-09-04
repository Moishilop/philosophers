#include "philo.h"

int	check_minus(char c)
{
	if (c == '-')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	long int	result;
	int			check_for_minus;
	int			i;

	result = 0;
	i = 0;
	check_for_minus = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		check_for_minus = check_minus(str[i]);
		i = i + 1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (int)str[i] - '0';
		i = i + 1;
	}
	if ((check_for_minus == 1 && result > 2147483648) || \
	(check_for_minus == 0 && result > 2147483647))
		return (-1);
	if (check_for_minus == 1)
		return (result * (-1));
	return (result);
}
