/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ra <mruiz-ra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 19:24:25 by mruiz-ra          #+#    #+#             */
/*   Updated: 2026/05/07 19:32:23 by mruiz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*next;

	if (*lst == NULL || del == NULL)
		return ;
	while (*lst != NULL)
	{
		current = *lst;
		del(current->content);
		next = current->next;
		free(*lst);
		*lst = next;
	}
}
