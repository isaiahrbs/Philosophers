#include "philo.h"
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
		// Cannot take second fork - only 1 fork exists
		// Just wait until death
		while (!simulation_ended(philo->simu))
			usleep(1000);
		pthread_mutex_unlock(&philo->simu->forks[0].mutex);
		return (0);
	}
	return (1);
}

int	take_forks(t_philo *philo)
{
	int	first_fork;
	int	second_fork;

	//check if there is one philo
	if (!check_alone(philo))
		return (0);

	/*
	-	avoiding deadlocks:
		waiting for the lower inder fork to be free before
		taking the higher inder number fork.
	*/
	if (philo->left_fork < philo->right_fork)
	{
		first_fork = philo->left_fork;
		second_fork = philo->right_fork;
	}
	else
	{
		first_fork = philo->right_fork;
		second_fork = philo->left_fork;
	}

	/*
		take the first fork & check if simu ended
		if simu ended, unlock and return (0);
	*/
	pthread_mutex_lock(&philo->simu->forks[first_fork].mutex);
	if (simulation_ended(philo->simu))
	{
		pthread_mutex_unlock(&philo->simu->forks[first_fork].mutex);
		return (0);
	}
	// set it as unavailable | 1 = available, 0 = unavailable
	philo->simu->forks[first_fork].available = 0;
	safe_print(philo, "has taken a fork. 🍴 [first fork]");

	//take the second fork
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
	safe_print(philo, "is eating. 🍽️");

	/*
	-	locking the meal so that there is no conflicts while
		changing the value of the meals eaten.
	*/
	pthread_mutex_lock(&philo->simu->meal_mutex);
	philo->last_meal_time = get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->simu->meal_mutex);

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
	printf("Entering routine loop\n");
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
	printf("Exiting Routine loop\n");
	return (NULL);
}
