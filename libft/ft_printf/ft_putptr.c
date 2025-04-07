/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:35:28 by irobinso          #+#    #+#             */
/*   Updated: 2025/01/26 18:09:07 by irobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void	ft_putnbr_ptr(unsigned long long nbr, char *base, int *count)
{
	if (nbr >= 16)
		ft_putnbr_ptr(nbr / 16, base, count);
	*count += write(1, &base[nbr % 16], 1);
}

ssize_t	ft_putptr(void *ptr)
{
	unsigned long long	addr;
	char				*base;
	int					count;

	count = write(1, "0x", 2);
	if (ptr == NULL)
		return (count + write(1, "0", 1));
	addr = (unsigned long long)ptr;
	base = "0123456789abcdef";
	ft_putnbr_ptr(addr, base, &count);
	return (count);
}

/*int main(void)
{
	void *ptr = (void *)0x1234567890abcdef;
	ft_putptr(ptr);
	return (0);
}*/
