/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ra <mruiz-ra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 11:50:13 by mruiz-ra          #+#    #+#             */
/*   Updated: 2026/05/07 21:02:19 by mruiz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	contador;

	contador = 0;
	if (n == 0)
		return (0);
	while (contador < n - 1 && s1[contador] != '\0' && s2[contador] != '\0')
	{
		if (s1[contador] > s2[contador])
			break ;
		else
		{
			if (s1[contador] < s2[contador])
				break ;
		}
		contador++;
	}
	return ((unsigned char)s1[contador] - (unsigned char)s2[contador]);
}
