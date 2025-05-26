#include "philo.h"
#include "utils.h"

int	main(int argc, char **argv)
{
	t_simu	simu;
	t_philo	*philos;//pointer to store multiple philosophers

	validate_input(argc, argv);
	init_simu(&simu, argc, argv);
	init_forks(&simu);
	init_philos(&philos, &simu);
	create_threads(&philos, &simu);
}