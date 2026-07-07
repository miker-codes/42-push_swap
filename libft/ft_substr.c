/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ra <mruiz-ra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 20:04:22 by mruiz-ra          #+#    #+#             */
/*   Updated: 2026/05/07 21:18:19 by mruiz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned char	*d;
	size_t			contador;

	contador = 0;
	if (start > ft_strlen(s))
	{
		d = malloc(1);
		if (d == NULL)
			return (NULL);
		d[0] = '\0';
		return ((char *)d);
	}
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	d = malloc(len + 1);
	if (d == NULL)
		return (NULL);
	while (contador < len && s[start] != '\0')
	{
		d[contador] = s[start];
		contador++;
		start++;
	}
	d[contador] = '\0';
	return ((char *)d);
}
