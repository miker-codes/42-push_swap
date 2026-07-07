/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ra <mruiz-ra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:00:25 by mruiz-ra          #+#    #+#             */
/*   Updated: 2026/05/07 20:35:47 by mruiz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		resultado;
	int		signo;
	size_t	contador;

	contador = 0;
	signo = 1;
	resultado = 0;
	while ((nptr[contador] >= 9
			&& nptr[contador] <= 13) || nptr[contador] == 32)
		contador++;
	if (nptr[contador] == '+' || nptr[contador] == '-')
	{
		if (nptr[contador] == '-')
			signo = signo * (-1);
		contador++;
	}
	while (ft_isdigit(nptr[contador]))
	{
		resultado = (resultado * 10) + (nptr[contador] - '0');
		contador++;
	}
	return (resultado * signo);
}
