/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:33:46 by irobinso          #+#    #+#             */
/*   Updated: 2025/01/26 18:09:12 by irobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void	printout(unsigned int nb)
{
	if (nb > 9)
		printout(nb / 10);
	if (nb <= 9)
	{
		ft_putchar(nb + 48);
		return ;
	}
	ft_putchar((nb % 10) + 48);
}

ssize_t	ft_putunbr(unsigned int nb)
{
	unsigned int	i;

	printout(nb);
	i = 1;
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}
