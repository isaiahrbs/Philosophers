/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:12:39 by irobinso          #+#    #+#             */
/*   Updated: 2025/05/28 17:37:09 by irobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include "utils.h"

int	take_forks(t_philo *philo)
{
	int	first_fork;
	int	second_fork;

	if (!check_alone(philo))
		return (0);
	assign_forks(philo, &first_fork, &second_fork);
	pthread_mutex_lock(&philo->simu->forks[first_fork].mutex);
	if (simulation_ended(philo->simu))
	{
		pthread_mutex_unlock(&philo->simu->forks[first_fork].mutex);
		return (0);
	}
	philo->simu->forks[first_fork].available = 0;
	safe_print(philo, "has taken a fork. 🍴 [first fork]");
	pthread_mutex_lock(&philo->simu->forks[second_fork].mutex);
	if (simulation_ended(philo->simu))
	{
		philo->simu->forks[first_fork].available = 1;
		pthread_mutex_unlock(&philo->simu->forks[first_fork].mutex);
		pthread_mutex_unlock(&philo->simu->forks[second_fork].mutex);
		return (0);
	}
	philo->simu->forks[second_fork].available = 0;
	safe_print(philo, "has taken a fork. 🍴 [second fork]");
	return (1);
}

void	put_forks(t_philo *philo)
{
	philo->simu->forks[philo->left_fork].available = 1;
	pthread_mutex_unlock(&philo->simu->forks[philo->left_fork].mutex);
	philo->simu->forks[philo->right_fork].available = 1;
	pthread_mutex_unlock(&philo->simu->forks[philo->right_fork].mutex);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->simu->meal_mutex);
	philo->last_meal_time = get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->simu->meal_mutex);
	safe_print(philo, "is eating. 🍽️");
	precise_usleep(philo->simu->time_to_eat * 1000);
}

void	sleep_and_think(t_philo *philo)
{
	safe_print(philo, "is sleeping. 😪🛏️");
	precise_usleep(philo->simu->time_to_sleep * 1000);
	safe_print(philo, "is thinking. 💭");
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		precise_usleep(philo->simu->time_to_eat * 500);
	while (!simulation_ended(philo->simu))
	{
		if (!take_forks(philo))
			break ;
		eat(philo);
		put_forks(philo);
		if (philo->simu->nb_meals > 0
			&& philo->meals_eaten >= philo->simu->nb_meals)
			break ;
		sleep_and_think(philo);
		//safe_print(philo, "finished a cycle. 🔄✅");
	}
	return (NULL);
}
