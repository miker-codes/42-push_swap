/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ra <mruiz-ra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 13:17:15 by mruiz-ra          #+#    #+#             */
/*   Updated: 2026/04/27 13:27:57 by mruiz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	contador;

	contador = 0;
	if (!s || !f)
		return ;
	while (s[contador] != '\0')
	{
		f(contador, &s[contador]);
		contador++;
	}
}
