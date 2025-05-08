#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

#define RED     "\033[31m"
#define RST     "\033[0m"

# define MAX_PHILO_NUM 300

typedef pthread_mutex_t t_mutex;

typedef struct s_philo
{
	pthread_t	thread;
	int			id;
	int			eating;
	int			meals_eaten;
	size_t		last_meal;
	size_t		time_to_die;
	size_t		time_to_eat;
	size_t		time_to_sleep;
	size_t		start_time;
	int			num_of_philos;
	int			num_times_to_eat;
	int			*dead;
	t_mutex		*right_fork;
	t_mutex		*left_fork;
	t_mutex		*write_lock;
	t_mutex		*dead_lock;
	t_mutex		*meal_lock;
}	t_philo;

typedef struct s_simu
{
	int		dead_flag;//*This means no philosopher has died at the start of the simulation
	t_mutex	dead_lock;//* so that only one thread updates the death count at a time.
	t_mutex	meal_lock;//* so monitor waits to read before the thread locks
	t_mutex	write_lock;//*ensures only one thread can write at a time
	t_philo	*philos;
}	t_simu;

//* main *//



//** init **//

void	init_simulation(t_simu *simu, t_philo *philos);
void	init_forks(pthread_mutex_t *forks, int philo_num);
void	init_philos(t_simu *simu, pthread_mutex_t *forks, char **argv);
void	init_input(char **argv, t_simu *simu);
void	*monitor(void *pointer);

//** utils **//

void	error_exit(char *str);


#endif
