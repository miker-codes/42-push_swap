/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ra <mruiz-ra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 18:08:11 by mruiz-ra          #+#    #+#             */
/*   Updated: 2026/05/07 21:11:09 by mruiz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_len(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_is_it_zero(void)
{
	char	*c;

	c = malloc(2);
	if (c == NULL)
		return (NULL);
	c[0] = '0';
	c[1] = '\0';
	return (c);
}

static char	*ft_aux_itoa(char *numerochar, long numero, int x, int n)
{
	int	digito;
	int	len;

	len = ft_num_len(n);
	while (numero > 0 && x >= (n < 0))
	{
		digito = numero % 10;
		numerochar[x] = digito + '0';
		numero = numero / 10;
		x--;
	}
	numerochar[len] = '\0';
	return (numerochar);
}

char	*ft_itoa(int n)
{
	char	*numerochar;
	long	numero;
	int		x;
	int		len;

	numero = n;
	len = ft_num_len(numero);
	if (numero == 0)
		return (ft_is_it_zero());
	numerochar = malloc(len + 1);
	if (numerochar == NULL)
		return (NULL);
	x = len - 1;
	if (numero < 0)
	{
		numerochar[0] = '-';
		numero = -numero;
	}
	return (ft_aux_itoa(numerochar, numero, x, n));
}
