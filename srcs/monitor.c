/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 19:34:00 by irobinso          #+#    #+#             */
/*   Updated: 2025/05/07 11:51:06 by irobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	output_message(char *str, t_philo *philo, int id)
{
	size_t	time;

	pthread_mutex_lock(philo->write_lock);
	time = get_precise_time() - philo->start_time;
	if (!dead_loop(philo))
		printf("PHILO: %d has %s\n", id, str);
	pthread_mutex_unlock(philo->write_lock)
}

int	is_dead(t_philo *philo, size_t time_to_die)
{
	pthread_mutex_lock(philo->meal_lock);
	if (get_precise_time() - philo->last_meal >= time_to_die
			&& philo->eating == 0)
	{
		pthread_mutex_unlock(philo->meal_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->meal_lock);
	return (0);
}

int	death_monitor(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos[0].num_of_philos)
	{
		if (is_dead(&philos[i], philos[i].time_to_die))
		{
			output_message("DIED", &philos[i], philos[i].id);
			pthread_mutex_lock(&philos[0].dead_lock);
			*philos->dead = 1;
			pthread_mutex_unlock(&philos[0].dead_lock);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ate_monitor(t_philo *philos)
{
	int	i;
	int	ate;

	i = 0;
	ate = 0;
	if (philos[0].num_times_to_eat == -1)
		return (0);
	while (i < philos[0].num_of_philos)
	{
		pthread_mutex_lock(philos[i].meal_lock);
		if (philos[i].meals_eaten >= philos[i].num_times_to_eat)
			ate++;
		pthread_mutex_unlock(philos[i].meal_lock);
		i++;
	}
	if (ate == philos[0].num_of_philos)
	{
		pthread_mutex_lock(philos[0].dead_lock);
		*philos->dead = 1;
		pthread_mutex_unlock(philos[0].dead_lock);
		return (1);
	}
	return (0);
}

void	*monitor(void *pointer)
{
	t_philo	*philos;

	philos = (t_philo *)pointer;
	while (1)
	{
		if (death_monitor(philos) == 1 || ate_monitor(philos) == 1)
			break;
	}
	return (pointer);
}