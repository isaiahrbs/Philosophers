/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:12:59 by irobinso          #+#    #+#             */
/*   Updated: 2025/05/28 10:24:01 by irobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include "utils.h"

int	check_alone(t_philo *philo)
{
	if (philo->simu->nb_philos == 1)
	{
		pthread_mutex_lock(&philo->simu->forks[0].mutex);
		if (simulation_ended(philo->simu))
		{
			pthread_mutex_unlock(&philo->simu->forks[0].mutex);
			return (0);
		}
		safe_print(philo, "has taken a fork. [first fork]");
		while (!simulation_ended(philo->simu))
			usleep(1);
		pthread_mutex_unlock(&philo->simu->forks[0].mutex);
		return (0);
	}
	return (1);
}

void	assign_forks(t_philo *philo, int *first_fork, int *second_fork)
{
	if (philo->id % 2 == 0)
	{
		*first_fork = philo->left_fork;
		*second_fork = philo->right_fork;
	}
	else
	{
		*first_fork = philo->right_fork;
		*second_fork = philo->left_fork;
	}
}
