/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ra <mruiz-ra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 19:25:57 by mruiz-ra          #+#    #+#             */
/*   Updated: 2026/05/07 20:34:26 by mruiz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	size_s;
	char	*d;

	size_s = ft_strlen(s);
	d = malloc(size_s + 1);
	if (d == NULL)
		return (NULL);
	ft_memcpy(d, s, size_s);
	d[size_s] = '\0';
	return (d);
}
