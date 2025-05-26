#include "philo.h"
#include "utils.h"

int	init_simu(t_simu *simu, int argc, char **argv)
{
	memset(simu, 0, sizeof(t_simu));// CHANGE THAT TO FT_
	
	simu->nb_philos = ft_atoi(argv[1]);
	simu->time_to_die = ft_atoi(argv[2]);
	simu->time_to_eat = ft_atoi(argv[3]);
	simu->time_to_sleep = ft_atoi(argv[4]);
	
	if (argc == 6)
		simu->nb_meals = ft_atoi(argv[5]);
	else
		simu->nb_meals = -1;
	
	// Simulation != finished & save Start time
	simu->simulation_end = FALSE;
	simu->start_time = get_current_time();

	// Initialize mutexes
	if (pthread_mutex_init(&simu->print_mutex, NULL) != 0)
		exit(EXIT_FAILURE);
	if (pthread_mutex_init(&simu->meal_mutex, NULL) != 0)
		exit(EXIT_FAILURE);
	if (pthread_mutex_init(&simu->end_mutex, NULL) != 0)
		exit(EXIT_FAILURE);

	return (0);
}

int	init_forks(t_simu *simu)
{
	int	i;

	simu->forks = malloc(sizeof(t_fork) * simu->nb_philos);
	if (!simu->forks)
		exit(EXIT_FAILURE);

	i = 0;
	while (i < simu->nb_philos)
	{
		if (pthread_mutex_init(&simu->forks[i].mutex, NULL) != 0)
		{
			// Clean up previously initialized mutexes
			while (--i >= 0)
				pthread_mutex_destroy(&simu->forks[i].mutex);
			free(simu->forks);
			exit(EXIT_FAILURE);
		}
		simu->forks[i].available = TRUE;
		i++;
	}
	return (0);
}

int	init_philos(t_philo **philos, t_simu *simu)
{
	int	i;

	*philos = malloc(sizeof(t_philo) * simu->nb_philos);
	if (!*philos)
		exit(EXIT_FAILURE);

	i = 0;
	while (i < simu->nb_philos)
	{
		(*philos)[i].id = i + 1;
		(*philos)[i].meals_eaten = 0;
		(*philos)[i].last_meal_time = simu->start_time;
		(*philos)[i].left_fork = i;
		(*philos)[i].right_fork = (i + 1) % simu->nb_philos;
		(*philos)[i].simu = simu;
		i++;
	}
	return (0);
}