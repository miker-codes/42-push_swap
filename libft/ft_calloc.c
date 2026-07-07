/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ra <mruiz-ra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 19:08:43 by mruiz-ra          #+#    #+#             */
/*   Updated: 2026/05/07 21:08:05 by mruiz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*p;
	size_t	totalsize;

	if (n == 0 || size == 0)
		return (malloc(0));
	if (size != 0 && n > SIZE_MAX / size)
		return (NULL);
	totalsize = n * size;
	p = malloc(totalsize);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, totalsize);
	return (p);
}
