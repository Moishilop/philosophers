#include "philo.h"

int	ft_check_nums(char *str)
{
	int	i;

	i = 0;
	while (i < ft_strlen(str))
	{
		if (ft_is_digit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	write_errors(int flag)
{
	if (flag == 1)
		printf("%sERROR: wrong number of args%s\n", RED, NONE);
	if (flag == 2)
		printf("%sERROR: error in arguments%s\n", RED, NONE);
	if (flag == 3)
		printf("%sERROR: wrong the optional argument%s\n", RED, NONE);
	return (1);
}

int	ft_parse(int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
		return (write_errors(1));
	i = 0;
	while (++i < argc)
	{	
		if (ft_check_nums(argv[i]) == 0 || ft_atoi(argv[i]) < 0 \
		|| ft_atoi(argv[1]) == 0)
			return (write_errors(2));
	}
	if (argc == 6)
	{
		if (ft_atoi(argv[argc - 1]) <= 0)
			return (write_errors(3));
	}
	return (0);
}
