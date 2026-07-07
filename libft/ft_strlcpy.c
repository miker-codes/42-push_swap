/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ra <mruiz-ra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 10:27:54 by mruiz-ra          #+#    #+#             */
/*   Updated: 2026/04/21 10:41:55 by mruiz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dsize)
{
	size_t	contador;

	contador = 0;
	if (dsize == 0)
		return (ft_strlen(src));
	while ((contador < dsize - 1) && src[contador] != '\0')
	{
		dst[contador] = src[contador];
		contador++;
	}
	dst[contador] = '\0';
	return (ft_strlen(src));
}
