/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ra <mruiz-ra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 09:56:37 by mruiz-ra          #+#    #+#             */
/*   Updated: 2026/04/21 10:24:51 by mruiz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			contador;
	unsigned char	*dest2;
	unsigned char	*src2;

	contador = 0;
	dest2 = (unsigned char *)dest;
	src2 = (unsigned char *)src;
	if (dest < src)
	{
		while (contador < n)
		{
			dest2[contador] = src2[contador];
			contador++;
		}
	}
	if (dest > src)
	{
		while (n > 0)
		{
			dest2[n - 1] = src2[n - 1];
			n--;
		}
	}
	return (dest);
}
