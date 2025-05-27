#include "philo.h"
#include "../inc/utils.h"

int	create_monitor_thread(t_philo **philos, t_simu *simu, pthread_t *p_monitor)
{
	int			i;

	if (pthread_create(p_monitor, NULL, monitor_routine, *philos) != 0)
	{
		simu->simulation_end = TRUE;
		i = 0;
		while (i < simu->nb_philos)
		{
			pthread_join((*philos)[i].thread, NULL);
			i++;
		}
		printf("·̣•Failed to created monitor thread\n");
		return (0);
	}
	printf("·̣•Created monitor thread\n");
	return (1);
}

int	create_threads(t_philo **philos, t_simu *simu)
{
	int			i;
	pthread_t	p_monitor;

	i = 0;
	// add a thread that will be given the monitor routine and if failed, cleanup */
	create_monitor_thread(philos, simu, &p_monitor);

	printf("Entered thread creation function\n");
	while (i < simu->nb_philos)
	{
		if (pthread_create(&(*philos)[i].thread, NULL, philo_routine, &(*philos)[i]) != 0)
		{
			printf("Thread creation failed\n");
            simu->simulation_end = TRUE;
			while (--i >= 0)
			pthread_join((*philos)[i].thread, NULL);
			printf("Cleanup! function: create_threads\n");
			cleanup(philos, simu);
			exit(EXIT_FAILURE);
		}
		printf("• Created thread\n");
		i++;
    }
	// wait for threads to finish
	pthread_join(p_monitor, NULL);
	return (1);
}
