/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:12:31 by irobinso          #+#    #+#             */
/*   Updated: 2025/06/03 08:35:50 by irobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include "utils.h"

int	monitor_deaths(t_philo *philos, t_simu *simu)
{
	int		i;
	long	current_time;
	long	time_since_meal;

	i = 0;
	while (i < simu->nb_philos)
	{
		pthread_mutex_lock(&simu->meal_mutex);
		if (simu->nb_meals > 0 && philos[i].meals_eaten >= simu->nb_meals)
		{
			pthread_mutex_unlock(&simu->meal_mutex);
			i++;
			continue ;
		}
		current_time = get_current_time();
		time_since_meal = current_time - philos[i].last_meal_time;
		pthread_mutex_unlock(&simu->meal_mutex);
		if (time_since_meal > simu->time_to_die)
		{
			safe_print(&philos[i], "⚰️ died");
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_meals_eaten(t_philo *philos, t_simu *simu)
{
	int	i;
	int	completed_meals;

	completed_meals = 0;
	i = 0;
	while (i < simu->nb_philos)
	{
		pthread_mutex_lock(&simu->meal_mutex);
		if (philos[i].meals_eaten >= simu->nb_meals)
			completed_meals++;
		pthread_mutex_unlock(&simu->meal_mutex);
		i++;
	}
	return (completed_meals == simu->nb_philos);
}

void	*monitor_routine(void *arg)
{
	t_philo	*philos;

	philos = (t_philo *)arg;
	while (!simulation_ended(philos->simu))
	{
		if (philos->simu->nb_meals > 0
			&& check_meals_eaten(philos, philos->simu))
		{
			set_simulation_end(philos->simu);
			break ;
		}
		if (monitor_deaths(philos, philos->simu))
		{
			set_simulation_end(philos->simu);
			break ;
		}
		usleep(100);
	}
	return (NULL);
}
