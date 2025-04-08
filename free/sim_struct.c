/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:52:57 by irobinso          #+#    #+#             */
/*   Updated: 2025/04/07 15:54:51 by irobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	free_struct(t_simulation *sim)
{
	int	i;

	i = 0;
	while (i < sim->philo_num)
	{
		pthread_mutex_destroy(&sim->forks[i]);
		free(sim->philos[i].thread);
		free(sim->philos[i].left_fork);
		free(sim->philos[i].right_fork);
		i++;
	}
	free(sim->forks);
	free(sim->philos);
	pthread_mutex_destroy(&sim->forks[i]);
	pthread_mutex_destroy(&sim->philos[i].left_fork);
	pthread_mutex_destroy(&sim->philos[i].right_fork);
	free(sim->philos[i].thread);
	free(sim->philos);
	free(sim);
}
