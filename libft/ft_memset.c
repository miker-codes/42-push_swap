/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ra <mruiz-ra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 20:46:57 by mruiz-ra          #+#    #+#             */
/*   Updated: 2026/04/20 21:06:06 by mruiz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			contador;
	unsigned char	*s2;

	contador = 0;
	s2 = (unsigned char *)s;
	while (contador < n)
	{
		s2[contador] = c;
		contador++;
	}
	return (s);
}
