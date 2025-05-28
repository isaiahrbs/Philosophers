/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:12:45 by irobinso          #+#    #+#             */
/*   Updated: 2025/05/28 13:22:55 by irobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include "../inc/utils.h"

int	create_monitor_thread(t_philo **philos, t_simu *simu, pthread_t *p_monitor)
{
	int			i;

	if (pthread_create(p_monitor, NULL, monitor_routine, *philos) != 0)
	{
		set_simulation_end(simu);
		i = 0;
		while (i < simu->nb_philos)
		{
			pthread_join((*philos)[i].thread, NULL);
			i++;
		}
		return (0);
	}
	return (1);
}

int	create_threads(t_philo **philos, t_simu *simu)
{
	int			i;
	pthread_t	p_monitor;

	i = 0;
	create_monitor_thread(philos, simu, &p_monitor);
	while (i < simu->nb_philos)
	{
		if (pthread_create(&(*philos)[i].thread, NULL,
			philo_routine, &(*philos)[i]) != 0)
		{
			set_simulation_end(simu);
			while (--i >= 0)
				pthread_join((*philos)[i].thread, NULL);
			cleanup(philos, simu);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	pthread_join(p_monitor, NULL);
	return (1);
}
