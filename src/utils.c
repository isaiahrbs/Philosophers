/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:12:57 by irobinso          #+#    #+#             */
/*   Updated: 2025/05/28 17:16:08 by irobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include "../inc/utils.h"

long	get_current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	precise_usleep(long microseconds)
{
	long	start_time;
	long	current_time;

	start_time = get_current_time() * 1000;
	while (1)
	{
		current_time = get_current_time() * 1000;
		if (current_time - start_time >= microseconds)
			break ;
		usleep(100);
	}
}

void	safe_print(t_philo *philo, char *action)
{
	long	timestamp;

	pthread_mutex_lock(&philo->simu->print_mutex);
	if (!simulation_ended(philo->simu))
	{
		timestamp = get_current_time() - philo->simu->start_time;
		printf("%ldms - P%d: %s\n", timestamp, philo->id, action);
	}
	pthread_mutex_unlock(&philo->simu->print_mutex);
}

int	simulation_ended(t_simu *simu)
{
	int	result;

	pthread_mutex_lock(&simu->end_mutex);
	result = simu->simulation_end;
	pthread_mutex_unlock(&simu->end_mutex);
	return (result);
}

void	set_simulation_end(t_simu *simu)
{
	pthread_mutex_lock(&simu->end_mutex);
	simu->simulation_end = TRUE;
	pthread_mutex_unlock(&simu->end_mutex);
}
