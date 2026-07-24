/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ra <mruiz-ra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 00:00:00 by mruiz-ra          #+#    #+#             */
/*   Updated: 2026/07/24 00:00:00 by mruiz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_no_flag(int first, int *start)
{
	if (first == -1)
	{
		*start = 1;
		return (1);
	}
	return (0);
}

int	ft_flag_single(int first, int *active, int *start)
{
	*start = 2;
	if (first != 4)
		return (first);
	*active = 1;
	return (0);
}

int	ft_flag_double(int first, int second, int *active, int *start)
{
	*start = 3;
	*active = 1;
	if (second != 4)
		return (second);
	return (first);
}
