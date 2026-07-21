/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ra <mruiz-ra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 10:56:09 by mruiz-ra          #+#    #+#             */
/*   Updated: 2026/07/13 10:56:09 by mruiz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;

t_node	*ft_new_node(int value);
void	ft_add_bottom(t_stack *stack, t_node *node);
void	ft_fill_stack(int argc, char **argv, t_stack *stack, int start);
void	ft_print_stack(t_stack *stack);
void	ft_init_stack(t_stack *stack);
int		ft_is_valid_int(char *str);
int		ft_validate_args(int argc, char **argv, int start);
int		ft_has_duplicates(t_stack *stack);
void	ft_free_stack(t_stack *stack);
void	ft_swap_top(t_stack *stack);
void	ft_sa(t_stack *a);
void	ft_sb(t_stack *b);
void	ft_ss(t_stack *a, t_stack *b);
void	ft_add_top(t_stack *stack, t_node *node);
t_node	*ft_pop_top(t_stack *stack);
void	ft_pa(t_stack *a, t_stack *b);
void	ft_pb(t_stack *a, t_stack *b);
void	ft_rotate_stack(t_stack *stack);
void	ft_ra(t_stack *a);
void	ft_rb(t_stack *b);
void	ft_rr(t_stack *a, t_stack *b);
t_node	*ft_pop_bottom(t_stack *stack);
void	ft_reverse_rotate_stack(t_stack *stack);
void	ft_rra(t_stack *a);
void	ft_rrb(t_stack *b);
void	ft_rrr(t_stack *a, t_stack *b);
int		ft_min_position(t_stack *stack);
void	ft_move_to_top(t_stack *stack, int pos);
void	ft_move_to_top_b(t_stack *b, int pos);
void	ft_sort_simple(t_stack *a, t_stack *b);
void	ft_normalize(t_stack *stack);
int		ft_count_bits(int size);
void	ft_sort_radix(t_stack *a, t_stack *b);
double	ft_disorder_index(t_stack *stack);
int		ft_chunk_size(int n);
int		ft_max_position(t_stack *stack);
void	ft_push_chunks(t_stack *a, t_stack *b, int chunk_size);
void	ft_sort_chunks(t_stack *a, t_stack *b);
int		ft_get_strategy(char *arg);
void	ft_dispatch(t_stack *a, t_stack *b, int strategy);

#endif
