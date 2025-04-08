/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:45:26 by irobinso          #+#    #+#             */
/*   Updated: 2025/04/07 16:11:12 by irobinso         ###   ########.fr       */
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
	long			last_meal_time;
}	t_philo;


typedef struct s_simulation
{
	int				philo_num;//number of philosophers
	pthread_mutex_t	*forks;//list of all forks
	t_philo			*philos;//list of all philosophers
}	t_simulation;



//* PHILOSOPHER FUNCTIONS *//

void	setup_sim_struct(t_simulation *sim);
void	checker(int argc, char **argv);

//* DEBUG FUNCTIONS *//

void	print_sim_stats(t_simulation *sim);


//* FREE FUNCTIONS *//

void	free_struct(t_simulation *sim);

#endif
