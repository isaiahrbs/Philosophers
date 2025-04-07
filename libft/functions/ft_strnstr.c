/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 07:06:42 by irobinso          #+#    #+#             */
/*   Updated: 2024/10/05 17:09:56 by irobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strnstr(const char *str, const char *search, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (search[0] == '\0')
		return ((char *)str);
	if (len == 0)
		return (NULL);
	while (str[i] != '\0' && i < len)
	{
		j = 0;
		while (str[i + j] == search[j] && (i + j) < len)
		{
			if (search[j + 1] == '\0')
				return ((char *)&str[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	char	*str = "hello world";
	char	*srch = "world";
	size_t	len = 11;

	char *result = ft_strnstr(str, srch, len);

	printf("String: %s\n", str);
	printf("Word to search: %s\n", srch);
	if (result != NULL)
	{
		printf("word found was found!\n");
	}
	else
	{
		printf("Word was not found\n");
	}
	return (0);
}*/
