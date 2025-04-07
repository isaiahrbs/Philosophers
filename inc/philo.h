#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <pthread.h>
# include "../libft/inc/libft.h"


typedef struct s_philo
{
	int				id;
	pthread_t		*thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	long			last_meal_time;
}	t_philo;


typedef struct s_simulation
{
	int				philo_num;//number of philosophers
	pthread_mutex_t	*forks;//list of all forks
	t_philo			*philos;//list of all philosophers
}	t_simulation;
