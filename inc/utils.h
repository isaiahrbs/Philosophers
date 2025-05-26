#ifndef UTILS_H
# define UTILS_H

// FUNCTIONS
// ---------

int	validate_input(int argc, char **argv);
int	init_philos(t_philo **philos, t_simu *simu);
int	init_forks(t_simu *simu);
int	init_simu(t_simu *simu, int argc, char **argv);

#endif