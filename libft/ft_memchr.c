/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ra <mruiz-ra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 13:12:16 by mruiz-ra          #+#    #+#             */
/*   Updated: 2026/05/07 20:48:00 by mruiz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			contador;
	unsigned char	*s2;

	if (n == 0)
		return (NULL);
	contador = 0;
	s2 = (unsigned char *)s;
	while (contador < n)
	{
		if (s2[contador] == (unsigned char)c)
			return (&s2[contador]);
		contador++;
	}
	return (NULL);
}
