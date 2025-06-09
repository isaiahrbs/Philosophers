/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:13:01 by irobinso          #+#    #+#             */
/*   Updated: 2025/06/09 14:03:56 by irobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"

static int	is_number_too_long(char *str)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		len++;
		i++;
	}
	return (len > 10);
}

static int	check_argument_ranges(int argc, char **argv)
{
	int	num_philos;
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (is_number_too_long(argv[i]))
		{
			printf("Error: Argument '%s' is above INTMAX\n", argv[i]);
			return (1);
		}
	}
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
