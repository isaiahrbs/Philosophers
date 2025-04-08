/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sim_stats.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:48:31 by irobinso          #+#    #+#             */
/*   Updated: 2025/04/07 15:51:47 by irobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	print_sim_stats(t_simulation *sim)
{
	printf("Philosophers: %d\n", sim->philo_num);
	printf("Forks: %p\n", sim->forks);
}
