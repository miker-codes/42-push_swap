/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ra <mruiz-ra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 19:21:45 by mruiz-ra          #+#    #+#             */
/*   Updated: 2026/07/22 20:11:01 by mruiz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_pair(char *name, int value)
{
	write(2, name, ft_strlen(name));
	write(2, ": ", 2);
	ft_putnbr_fd(value, 2);
	write(2, " ", 1);
}

void	ft_print_count(t_bench *bench)
{
	write(2, "[bench] ", 8);
	ft_print_pair("sa", bench->count[0]);
	ft_print_pair("sb", bench->count[1]);
	ft_print_pair("ss", bench->count[2]);
	ft_print_pair("pa", bench->count[3]);
	ft_print_pair("pb", bench->count[4]);
	write(2, "\n", 1);
	write(2, "[bench] ", 8);
	ft_print_pair("ra", bench->count[5]);
	ft_print_pair("rb", bench->count[6]);
	ft_print_pair("rr", bench->count[7]);
	ft_print_pair("rra", bench->count[8]);
	ft_print_pair("rrb", bench->count[9]);
	ft_print_pair("rrr", bench->count[10]);
	write(2, "\n", 1);
}
