/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ra <mruiz-ra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 13:44:31 by mruiz-ra          #+#    #+#             */
/*   Updated: 2026/05/07 21:16:24 by mruiz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	contador;
	size_t	contador2;

	if (little[0] == '\0')
		return ((char *)big);
	contador = 0;
	while (big[contador] != '\0' && contador < len)
	{
		contador2 = 0;
		while (big[contador + contador2] == little[contador2]
			&& (contador + contador2) < len
			&& little[contador2] != '\0')
		{
			contador2++;
		}
		if (little[contador2] == '\0')
			return ((char *)&big[contador]);
		contador++;
	}
	return (NULL);
}
