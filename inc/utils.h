/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:11:40 by irobinso          #+#    #+#             */
/*   Updated: 2025/05/27 16:13:19 by irobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "philo.h"

// FUNCTIONS
// ---------

int		validate_input(int argc, char **argv);
int		init_philos(t_philo **philos, t_simu *simu);
int		init_forks(t_simu *simu);
int		init_simu(t_simu *simu, int argc, char **argv);
int		create_threads(t_philo **philos, t_simu *simu);
void	*philo_routine(void *arg);
void	*monitor_routine(void *arg);

// UTILS
// --------
int		ft_atoi(const char *str);
int		simulation_ended(t_simu *simu);
long	get_current_time(void);
void	precise_usleep(long microseconds);
void	safe_print(t_philo *philo, char *action);
int		is_valid_number(const char *str);
void	cleanup(t_philo **philos, t_simu *simu);
void	set_simulation_end(t_simu *simu);

#endif
