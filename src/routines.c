#include "philo.h"
#include "utils.h"

void	eat(t_philo *philo)
{
	safe_print(philo, "is eating");

	pthread_mutex_lock(&philo->simu->meal_mutex);
	philo->last_meal_time = get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->simu->meal_mutex);

	precise_usleep(philo->simu->time_to_eat * 1000);
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

		// check if phlosophers has eaten enough meals
		if (philo->simu->nb_meals > 0 && philo->meals_eaten >= philo->simu->nb_meals)
			break ;

		sleep_and_think(philo);
	}
	return (NULL);
}
