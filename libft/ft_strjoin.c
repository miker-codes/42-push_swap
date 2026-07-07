/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ra <mruiz-ra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 20:21:03 by mruiz-ra          #+#    #+#             */
/*   Updated: 2026/05/07 21:25:41 by mruiz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*d;
	size_t			totalsize;
	size_t			contador;

	contador = 0;
	totalsize = ft_strlen(s1) + ft_strlen(s2);
	d = malloc(totalsize + 1);
	if (d == NULL)
		return (NULL);
	d[0] = '\0';
	while (s1[contador] != '\0')
	{
		d[contador] = s1[contador];
		contador++;
	}
	d[contador] = '\0';
	ft_strlcat(d, s2, totalsize + 1);
	return (d);
}
