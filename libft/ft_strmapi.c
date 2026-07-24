/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ra <mruiz-ra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 21:55:40 by mruiz-ra          #+#    #+#             */
/*   Updated: 2026/04/27 13:29:22 by mruiz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*dest;
	unsigned int	contador;

	contador = 0;
	if (!s || !f)
		return (NULL);
	dest = malloc(ft_strlen(s) + 1);
	if (dest == NULL)
		return (NULL);
	while (s[contador] != '\0')
	{
		dest[contador] = f(contador, s[contador]);
		contador++;
	}
	dest[contador] = '\0';
	return (dest);
}
