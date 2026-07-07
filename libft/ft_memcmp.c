/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ra <mruiz-ra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 13:34:46 by mruiz-ra          #+#    #+#             */
/*   Updated: 2026/04/21 13:42:56 by mruiz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			contador;
	unsigned char	*s1copy;
	unsigned char	*s2copy;

	contador = 0;
	s1copy = (unsigned char *)s1;
	s2copy = (unsigned char *)s2;
	while (contador < n)
	{
		if (s1copy[contador] < s2copy[contador])
			return (-1);
		else
		{
			if (s1copy[contador] > s2copy[contador])
				return (1);
		}
		contador++;
	}
	return (0);
}
