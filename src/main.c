/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:12:24 by irobinso          #+#    #+#             */
/*   Updated: 2025/05/27 16:12:25 by irobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	while (!simulation_ended(&simu))
	{
		usleep(1000);
	}
	if (simu.simulation_end)
		cleanup(&philos, &simu);
	return (0);
}
