#include "philo.h"
#include "utils.h"

int	create_threads(t_philo *philos, t_simu *simu)
{
	int	i;

	i = 0;
	while (i < simu->nb_philos)
	{
		if (pthread_create(&philos[i].thread, NULL, &philo_routine, &philos[i]) != 0)
		{
			simu->simulation_end = TRUE;
			while (--i >= 0)
				pthread_join(philos[i].thread, NULL);
			cleanup(philos, simu);
		}
		i++;
	}
	// add a thread that will be given the monitor routine and if failed, cleanup
}
