/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ra <mruiz-ra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 15:57:35 by mruiz-ra          #+#    #+#             */
/*   Updated: 2026/07/20 15:57:35 by mruiz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		strategy;
	int		start;

	if (argc < 2)
		return (0);
	ft_init_stack(&a);
	ft_init_stack(&b);
	strategy = 0;
	start = 1;
	if (argv[1][0] == '-' && argv[1][1] == '-')
	{
		strategy = ft_get_strategy(argv[1]);
		if (strategy == -1)
			return (ft_putstr_fd("Error\n", 2), 1);
		start = 2;
	}
	if (!ft_validate_args(argc, argv, start))
		return (ft_putstr_fd("Error\n", 2), 1);
	ft_fill_stack(argc, argv, &a, start);
	if (ft_has_duplicates(&a))
		return (ft_free_stack(&a), ft_putstr_fd("Error\n", 2), 1);
	ft_normalize(&a);
	ft_dispatch(&a, &b, strategy);
	ft_free_stack(&a);
	ft_free_stack(&b);
	return (0);
}
