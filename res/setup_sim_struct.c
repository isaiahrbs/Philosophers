/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_sim_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:48:34 by irobinso          #+#    #+#             */
/*   Updated: 2025/04/24 14:45:14 by irobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	init_struct(t_sim *sim, int argc, char **argv)
{
	(void)argc;

	sim->philo_num = ft_atoi(argv[1]);
	sim->time_to_die = ft_atoi(argv[2]);
	sim->time_to_eat = ft_atoi(argv[3]);
	sim->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		sim->amount_to_eat = ft_atoi(argv[5]);
	else
		sim->amount_to_eat = -1;
	sim->forks = NULL;
	sim->philos = NULL;
}

//for the line 48 : &sim->forks[(i + 1) % sim->philo_num]: Points to the fork to the right of philosopher i. The modulo ensures that after the last philosopher, the right fork wraps back to the first one, creating a circular arrangement.
void	set_philos_with_id(t_sim *sim)
{
	int	i;

	sim->philos = malloc(sizeof(t_philo) * sim->philo_num);
	if (!sim->philos)
	{
		printf("Error: malloc for philosophers failed\n");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < sim->philo_num)
	{
		sim->philos[i].id = i;
		sim->philos[i].last_meal_time = 0;
		sim->philos[i].left_fork = &sim->forks[i];
		sim->philos[i].right_fork = &sim->forks[(i + 1) % sim->philo_num];
		sim->philos[i].meals_eaten = 0;
		i++;
	}
}

void	setup_forks(t_sim *sim)
{
	int	i;

	sim->forks = malloc(sizeof(pthread_mutex_t) * (sim->philo_num));
	if (!sim->forks)
	{
		printf("error: malloc forks\n");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < sim->philo_num)
	{
		if (pthread_mutex_init(&sim->forks[i], NULL) != 0)
		{
			printf("error: mutex init\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

// MALLOC THE SIZE AND SET ALL TO NULL //
void	setup_sim_struct(t_sim *sim, int argc, char **agrv)
{
	init_struct(sim, argc, agrv);
	setup_forks(sim);
	setup_philos_with_id(sim);
}
