/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ra <mruiz-ra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 11:15:50 by mruiz-ra          #+#    #+#             */
/*   Updated: 2026/05/07 20:50:03 by mruiz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	contador;

	contador = 0;
	while (s[contador] != '\0')
	{
		if (s[contador] == (char)c)
			return ((char *)&s[contador]);
		contador++;
	}
	if ((char)c == '\0')
		return ((char *)&s[contador]);
	return (NULL);
}
