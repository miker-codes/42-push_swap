/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ra <mruiz-ra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 21:11:57 by mruiz-ra          #+#    #+#             */
/*   Updated: 2026/05/07 20:34:10 by mruiz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			contador;
	unsigned char	*src2;
	unsigned char	*dest2;

	contador = 0;
	src2 = (unsigned char *)src;
	dest2 = (unsigned char *)dest;
	while (contador < n)
	{
		dest2[contador] = src2[contador];
		contador++;
	}
	return (dest);
}
