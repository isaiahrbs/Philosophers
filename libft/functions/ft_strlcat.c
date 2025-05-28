/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 02:14:51 by irobinso          #+#    #+#             */
/*   Updated: 2024/10/08 10:37:15 by irobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	a;
	size_t	b;
	size_t	c;
	size_t	d;

	d = ft_strlen(src);
	if (!dst && size == 0)
		return (d);
	b = ft_strlen(dst);
	c = b;
	if (size <= c)
		return (size + d);
	a = 0;
	while (src[a] && b + 1 < size)
	{
		dst[b] = src[a];
		a++;
		b++;
	}
	dst[b] = 0;
	return (c + d);
}

/*int main(void)
{
	char dest[100] = "Hello";
	char src[100] = "World!";
	size_t size = 10;

	strlcat(dest, src, size);
	printf("%s\n", dest);

	return (0);
}*/
