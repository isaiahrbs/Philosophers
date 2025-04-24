/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:45:26 by irobinso          #+#    #+#             */
/*   Updated: 2025/04/24 14:40:11 by irobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int				meals_eaten;
	long			last_meal_time;
}	t_philo;

typedef struct s_sim
{
	int				philo_num;//number of philosophers
	pthread_mutex_t	*forks;//list of all forks
	t_philo			*philos;//list of all philosophers
	int				time_to_die;
	int				time_to_sleep;
	int				time_to_eat;
	int				amount_to_eat;
	long			start_time;
	int				end_sim;
}	t_sim;

//* PHILOSOPHER FUNCTIONS *//

void	setup_sim_struct(t_sim *sim, int argc, char **agrv);
void	checker(int argc, char **argv);

//* DEBUG FUNCTIONS *//

void	print_sim_stats(t_sim *sim);

//* FREE FUNCTIONS *//

void	free_struct(t_sim *sim);

#endif
