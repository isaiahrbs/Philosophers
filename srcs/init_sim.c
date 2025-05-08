/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:50:13 by irobinso          #+#    #+#             */
/*   Updated: 2025/05/06 19:33:51 by irobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init_input(char **argv, t_simu *simu)
{
	int	i;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		simu->philos[i].time_to_die = ft_atoi(argv[2]);
		simu->philos[i].time_to_eat = ft_atoi(argv[3]);
		simu->philos[i].time_to_sleep = ft_atoi(argv[4]);
		simu->philos[i].num_of_philos = ft_atoi(argv[1]);
		if (argv[5])
			simu->philos[i].num_times_to_eat = ft_atoi(argv[5]);
		else
			simu->philos[i].num_times_to_eat = -1;
		i++;
	}
}


void	init_philos(t_simu *simu, t_mutex *forks, char **argv)
{
	int	i;
	int	total;

	i = 0;
	total = ft_atoi(argv[1]);
	while (i < total)
	{
		simu->philos[i].id = i + 1;
		simu->philos[i].eating = 0;
		simu->philos[i].meals_eaten = 0;
		simu->philos[i].start_time = get_current_time();
		simu->philos[i].last_meal = get_current_time();
		simu->philos[i].write_lock = &simu->write_lock;
		simu->philos[i].dead_lock = &simu->dead_lock;
		simu->philos[i].meal_lock = &simu->meal_lock;
		simu->philos[i].dead = &simu->dead_flag;
		simu->philos[i].left_fork = &forks[i];
		simu->philos[i].right_fork = &forks[(i + 1) % total];// maybe need to change
		i++;
	}
}

void	init_forks(t_mutex *forks, int philo_num)
{
	int	i;

	i = 0;
	while (i < philo_num)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	init_simulation(t_simu *simu, t_philo *philos)
{
	simu->dead_flag = 0;
	simu->philos = philos;
	pthread_mutex_init(&simu->write_lock, NULL);
	pthread_mutex_init(&simu->dead_lock, NULL);
	pthread_mutex_init(&simu->meal_lock, NULL);
}
