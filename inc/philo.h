/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:11:03 by irobinso          #+#    #+#             */
/*   Updated: 2025/05/27 16:13:33 by irobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>

# define MAX_PHILOS 200
# define TRUE 1
# define FALSE 0

typedef struct s_fork
{
	pthread_mutex_t	mutex;
	int				available;
}	t_fork;

typedef struct s_simu
{
	int				nb_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_meals;
	int				simulation_end;
	long			start_time;
	t_fork			*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	meal_mutex;
	pthread_mutex_t	end_mutex;
}	t_simu;

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	long			last_meal_time;
	int				left_fork;
	int				right_fork;
	pthread_t		thread;
	t_simu			*simu;
}	t_philo;

#endif
