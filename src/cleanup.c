/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:11:43 by irobinso          #+#    #+#             */
/*   Updated: 2025/05/27 16:12:08 by irobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"

void	cleanup_mutexes(t_simu *simu)
{
	if (simu)
	{
		pthread_mutex_destroy(&simu->print_mutex);
		pthread_mutex_destroy(&simu->meal_mutex);
		pthread_mutex_destroy(&simu->end_mutex);
	}
}

void	cleanup_forks(t_simu *simu)
{
	int	i;

	if (simu && simu->forks)
	{
		i = 0;
		while (i < simu->nb_philos)
		{
			pthread_mutex_destroy(&simu->forks[i].mutex);
			i++;
		}
		free(simu->forks);
		simu->forks = NULL;
	}
}

void	cleanup_threads(t_philo **philos, t_simu *simu)
{
	int	i;

	if (philos && *philos && simu)
	{
		i = 0;
		while (i < simu->nb_philos)
		{
			if ((*philos)[i].thread)
				pthread_join((*philos)[i].thread, NULL);
			i++;
		}
	}
}

void	cleanup(t_philo **philos, t_simu *simu)
{
	if (simu)
		set_simulation_end(simu);
	cleanup_threads(philos, simu);
	cleanup_forks(simu);
	cleanup_mutexes(simu);
	if (philos && *philos)
	{
		free(*philos);
		*philos = NULL;
	}
}
