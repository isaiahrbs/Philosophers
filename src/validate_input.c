#include "philo.h"
#include "utils.h"

static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static int	is_valid_number(const char *str)
{
	int	i;

	if (!str || !*str)
		return (0);
	i = 0;
	if (str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!is_digit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	check_argument_ranges(int argc, char **argv)
{
	int	num_philos;

	num_philos = ft_atoi(argv[1]);
	if (num_philos < 1 || num_philos > 200)
		return (printf("Error: Number of philosophers must be 1-200\n"), 1);
	if (ft_atoi(argv[2]) < 60)
		return (printf("Error: time_to_die must be >= 60ms\n"), 1);
	if (ft_atoi(argv[3]) < 60)
		return (printf("Error: time_to_eat must be >= 60ms\n"), 1);
	if (ft_atoi(argv[4]) < 60)
		return (printf("Error: time_to_sleep must be >= 60ms\n"), 1);
	if (argc == 6 && ft_atoi(argv[5]) < 1)
		return (printf("Error: must_eat_count must be >= 1\n"), 1);
	return (0);
}

int	validate_input(int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
	{
		printf("Usage: %s number_of_philosophers time_to_die ", argv[0]);
		printf("time_to_eat time_to_sleep [number_of_times_each_");
		printf("philosopher_must_eat]\n");
		exit(EXIT_FAILURE);
	}
	i = 1;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
		{
			printf("Error: Invalid argument '%s'\n", argv[i]);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (check_argument_ranges(argc, argv));
}
