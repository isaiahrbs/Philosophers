/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 04:02:06 by irobinso          #+#    #+#             */
/*   Updated: 2025/01/26 18:08:52 by irobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

ssize_t	convert(const char *str, va_list *args)
{
	if (*(str + 1) == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (*(str + 1) == 's')
		return (ft_putstr((char *)va_arg(*args, char *)));
	else if (*(str + 1) == 'd' || *(str + 1) == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	else if (*(str + 1) == 'u')
		return (ft_putunbr(va_arg(*args, unsigned int)));
	else if (*(str + 1) == 'x')
		return (ft_putnbrbasehex(va_arg(*args, unsigned int), 0));
	else if (*(str + 1) == 'X')
		return (ft_putnbrbasehex(va_arg(*args, unsigned int), 1));
	else if (*(str + 1) == '%')
		return (ft_putchar('%'));
	else if (*(str + 1) == 'p')
		return (ft_putptr(va_arg(*args, void *)));
	else if (*(str + 1) == '\0')
		return (0);
	else
		return (-1);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			count += convert(str + i, &args);
			i += 1;
		}
		else
		{
			ft_putchar(str[i]);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

/*int	main(void)
{
	int tester;
	ssize_t ui = 53327;
	int	i = 10;
	char c = 'a';

	tester = ft_printf("int: %d unsigned int: %u);
	ft_printf("%d", i);
	return (0);
}*/
