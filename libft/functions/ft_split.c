/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 22:57:51 by isaiah            #+#    #+#             */
/*   Updated: 2024/10/10 10:21:12 by irobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	safe_malloc(char **array, int pos, size_t buffer)
{
	int	i;

	i = 0;
	array[pos] = malloc(buffer);
	if (array[pos] == NULL)
	{
		while (i < pos)
		{
			free(array[i++]);
		}
		free(array);
		return (1);
	}
	return (0);
}

int	fill(char **array, char const *s, char c)
{
	size_t	len;
	int		i;

	i = 0;
	while (*s)
	{
		len = 0;
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
		{
			len++;
			s++;
		}
		if (len > 0)
		{
			if (safe_malloc(array, i, len + 1) == 1)
				return (1);
			ft_strlcpy(array[i], s - len, len + 1);
			i++;
		}
	}
	return (0);
}

size_t	count_words(char const *s, char c)
{
	size_t	word_count;
	int		in_word;

	word_count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			word_count++;
			in_word = 1;
		}
		else if (*s == c)
		{
			in_word = 0;
		}
		s++;
	}
	return (word_count);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**array;

	if (s == NULL)
		return (NULL);
	words = count_words(s, c);
	array = malloc(sizeof(char *) * (words + 1));
	if (array == NULL)
		return (NULL);
	array[words] = NULL;
	if (fill(array, s, c) == 1)
		return (NULL);
	return (array);
}

/*int	main(void)
{
	char *s = "    Hello there,       dude!!!";

	char **array = ft_split(s, ' ');

	while (*array)
	{
		printf("%s\n", *array++);
	}
}*/
