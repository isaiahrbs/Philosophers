/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_sim_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:48:34 by irobinso          #+#    #+#             */
/*   Updated: 2025/04/07 15:48:37 by irobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"


// MALLOC THE SIZE AND SET ALL TO NULL //
void	setup_sim_struct(t_simulation *sim)
{
	sim = malloc(sizeof(t_simulation));
	if (!sim)
	{
		printf("Failed to allocate memory for simulation structure\n");
		exit(EXIT_FAILURE);
	}
	sim->philo_num = 0;
	sim->forks = NULL;
	sim->philos = NULL;
}
