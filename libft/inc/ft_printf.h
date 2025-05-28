/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 04:56:55 by irobinso          #+#    #+#             */
/*   Updated: 2025/01/26 18:57:25 by irobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

int			ft_printf(const char *str, ...);
ssize_t		ft_putchar(char c);
ssize_t		ft_putstr(char *str);
ssize_t		ft_putnbr(int n);
ssize_t		ft_putunbr(unsigned int n);
ssize_t		ft_putnbrbasehex(unsigned int n, int index);
ssize_t		ft_putptr(void *ptr);

#endif
