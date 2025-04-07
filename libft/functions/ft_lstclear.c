/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:02:51 by irobinso          #+#    #+#             */
/*   Updated: 2024/10/10 17:16:23 by irobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*l;

	if (!lst || !del)
		return ;
	while (*lst != NULL)
	{
		l = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = l;
	}
	*lst = NULL;
}
