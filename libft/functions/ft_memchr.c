/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 06:20:56 by irobinso          #+#    #+#             */
/*   Updated: 2024/10/04 10:59:32 by irobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*s;
	unsigned char	uc;

	s = (unsigned char *)str;
	uc = (unsigned char)c;
	while (n > 0)
	{
		if (*s == uc)
		{
			return ((void *)s);
		}
		s++;
		n--;
	}
	return (NULL);
}
