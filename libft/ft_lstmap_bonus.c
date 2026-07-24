/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ra <mruiz-ra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 19:38:55 by mruiz-ra          #+#    #+#             */
/*   Updated: 2026/05/09 12:00:20 by mruiz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*new_nodo;
	void	*content;

	result = NULL;
	while (lst != NULL)
	{
		content = f(lst->content);
		new_nodo = ft_lstnew(content);
		if (new_nodo == NULL)
		{
			del(content);
			ft_lstclear(&result, del);
			return (NULL);
		}
		ft_lstadd_back(&result, new_nodo);
		lst = lst->next;
	}
	return (result);
}
