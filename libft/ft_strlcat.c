/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ra <mruiz-ra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 10:42:44 by mruiz-ra          #+#    #+#             */
/*   Updated: 2026/05/07 20:54:54 by mruiz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	size_t	contador;
	size_t	contadorsrc;
	size_t	dst_init_len;

	if (dsize == 0)
		return (ft_strlen(src));
	dst_init_len = ft_strlen(dst);
	if (dsize <= dst_init_len)
		return (dsize + ft_strlen(src));
	contadorsrc = 0;
	contador = dst_init_len;
	while ((contador < dsize - 1) && src[contadorsrc] != '\0')
	{
		dst[contador] = src[contadorsrc];
		contador++;
		contadorsrc++;
	}
	dst[contador] = '\0';
	return (ft_strlen(src) + dst_init_len);
}
