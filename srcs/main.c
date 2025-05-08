/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:31:57 by irobinso          #+#    #+#             */
/*   Updated: 2025/05/06 17:30:40 by irobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_isnum(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

//* COMPRIS
int	check_args(int argc, char **argv)
{
	if (argc != 5 || argc != 6)
		error_exit("Wrong argument count");
	if (ft_atoi(argv[1]) > MAX_PHILO_NUM || ft_atoi(argv[1]) <= 0
		|| ft_isnum(argv[1]) == 1)
		return (fprintf(stderr, "Invalid philosophers number\n"), 1);
	if (ft_atoi(argv[2]) <= 0 || ft_isnum(argv[2]) == 1)
		return (fprintf(stderr, "Invalid time to die\n"), 1);
	if (ft_atoi(argv[3]) <= 0 || ft_isnum(argv[3]) == 1)
		return (fprintf(stderr, "Invalid time to eat\n"), 1);
	if (ft_atoi(argv[4]) <= 0 || ft_isnum(argv[4]) == 1)
		return (fprintf(stderr, "Invalid time to sleep\n"), 1);
	if (argv[5] && (ft_atoi(argv[5]) < 0 || ft_isnum(argv[5]) == 1))
		return (fprintf(stderr,
			"Invalid number of times each philosopher must eat\n"), 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_simu	simulation;
	t_philo	philos[MAX_PHILO_NUM];
	t_mutex	forks[MAX_PHILO_NUM];

	if (check_args(argc, argv) == 1)
		return (1);
	init_simulation(&simulation, philos);
	init_forks(forks, ft_atoi(argv[1]));
	init_philos(&simulation, forks, argv);
	init_input(argv, &simulation);
	create_threads(NULL, &simulation, forks);
	purge(NULL, &simulation, forks);
	return (0);
}
