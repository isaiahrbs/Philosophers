/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:18:07 by irobinso          #+#    #+#             */
/*   Updated: 2024/10/08 10:07:35 by irobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (s1[i])
		res[j++] = s1[i++];
	i = 0;
	while (s2[i])
		res[j++] = s2[i++];
	res[j] = 0;
	return (res);
}

/*int main(void)
{
	const char *s1 = "hello";
	const char *s2 = "world";

	char	*strjoin = ft_strjoin(s1, s2);

	if (strjoin)
	{
		printf("strjoin: %s\n", strjoin);
		free(strjoin);
	}
	else
	{
		printf("Memory allocation failed\n");
	}
	return (0);
}*/
