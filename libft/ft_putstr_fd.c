/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ra <mruiz-ra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 13:35:01 by mruiz-ra          #+#    #+#             */
/*   Updated: 2026/04/27 13:37:46 by mruiz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	contador;

	if (!s)
		return ;
	contador = 0;
	while (s[contador] != '\0')
	{
		write(fd, &s[contador], 1);
		contador++;
	}
}
