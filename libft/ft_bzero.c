/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ra <mruiz-ra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 21:07:25 by mruiz-ra          #+#    #+#             */
/*   Updated: 2026/04/20 21:11:20 by mruiz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			contador;
	unsigned char	*s2;

	contador = 0;
	s2 = (unsigned char *)s;
	while (contador < n)
	{
		s2[contador] = 0;
		contador++;
	}
}
