/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:08:24 by irobinso          #+#    #+#             */
/*   Updated: 2025/04/23 15:26:48 by irobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	is_all_digits(char *str)
{
	int i = 0;
	if (!str || str[0] == '\0')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	check_one(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		printf("Usage: ./philo number_of_philosophers time_to_die ");
		printf("time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
		exit(EXIT_FAILURE);
	}
	if (!is_all_digits(argv[1]) || !is_all_digits(argv[2]) ||
		!is_all_digits(argv[3]) || !is_all_digits(argv[4]) ||
		(argc == 6 && !is_all_digits(argv[5])))
	{
		printf("Error: All arguments must be positive integers.\n");
		exit(EXIT_FAILURE);
	}
	if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[2]) <= 0 ||
		ft_atoi(argv[3]) <= 0 || ft_atoi(argv[4]) <= 0 ||
		(argc == 6 && ft_atoi(argv[5]) <= 0))
	{
		printf("Error: All arguments must be positive integers greater than 0.\n");
		exit(EXIT_FAILURE);
	}
	if (ft_atoi(argv[1]) > 200)
	{
		printf("Error: Number of philosophers must be less than or equal to 200.\n");
		exit(EXIT_FAILURE);
	}
}

void	checker(int argc, char **argv)
{
	check_one(argc, argv);
	if (ft_atoi(argv[1]) == 1)
	{
		printf("Error: Number of philosophers must be greater than 1.\n");
		exit(EXIT_FAILURE);
	}
	if (ft_atoi(argv[2]) < ft_atoi(argv[3]) || ft_atoi(argv[2]) < ft_atoi(argv[4]))
	{
		printf("Error: Time to die must be greater than time to eat and time to sleep.\n");
		exit(EXIT_FAILURE);
	}
}
