/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaiah <isaiah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:12:24 by irobinso          #+#    #+#             */
/*   Updated: 2025/06/03 14:34:34 by isaiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"

int	main(int argc, char **argv)
{
	t_simu	simu;
	t_philo	*philos;

	if (validate_input(argc, argv))
		return (1);
	init_simu(&simu, argc, argv);
	init_forks(&simu);
	init_philos(&philos, &simu);
	create_threads(&philos, &simu);
	while (!simulation_ended(&simu))
	{
		usleep(1000);
	}
	cleanup(&philos, &simu);
	return (0);
}
