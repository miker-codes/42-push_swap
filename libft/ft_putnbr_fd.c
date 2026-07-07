/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ra <mruiz-ra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 13:46:01 by mruiz-ra          #+#    #+#             */
/*   Updated: 2026/04/27 14:11:10 by mruiz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	num;
	int		div;

	num = n;
	div = 1;
	if (num < 0)
	{
		write(fd, "-", 1);
		num = -num;
	}
	while (num / div >= 10)
		div *= 10;
	while (div > 0)
	{
		ft_putchar_fd((num / div) + '0', fd);
		num %= div;
		div /= 10;
	}
}
