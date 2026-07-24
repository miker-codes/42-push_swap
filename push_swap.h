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

typedef struct s_bench
{
	int		active;
	double	disorder;
	int		count[11];
	int		complexity;
}	t_bench;

t_node	*ft_new_node(int value);
void	ft_add_bottom(t_stack *stack, t_node *node);
int		ft_fill_stack(char **argv, t_stack *stack, int start);
void	ft_init_stack(t_stack *stack);
int		ft_is_valid_int(char *str);
int		ft_validate_args(char **argv, int start);
int		ft_has_duplicates(t_stack *stack);
void	ft_free_stack(t_stack *stack);
void	ft_swap_top(t_stack *stack);
void	ft_sa(t_stack *a, t_bench *bench);
void	ft_sb(t_stack *b, t_bench *bench);
void	ft_ss(t_stack *a, t_stack *b, t_bench *bench);
void	ft_add_top(t_stack *stack, t_node *node);
t_node	*ft_pop_top(t_stack *stack);
void	ft_pa(t_stack *a, t_stack *b, t_bench *bench);
void	ft_pb(t_stack *a, t_stack *b, t_bench *bench);
void	ft_rotate_stack(t_stack *stack);
void	ft_ra(t_stack *a, t_bench *bench);
void	ft_rb(t_stack *b, t_bench *bench);
void	ft_rr(t_stack *a, t_stack *b, t_bench *bench);
t_node	*ft_pop_bottom(t_stack *stack);
void	ft_reverse_rotate_stack(t_stack *stack);
void	ft_rra(t_stack *a, t_bench *bench);
void	ft_rrb(t_stack *b, t_bench *bench);
void	ft_rrr(t_stack *a, t_stack *b, t_bench *bench);
int		ft_min_position(t_stack *stack);
void	ft_move_to_top(t_stack *stack, int pos, int flag, t_bench *bench);
void	ft_sort_simple(t_stack *a, t_stack *b, t_bench *bench);
void	ft_normalize(t_stack *stack);
int		ft_count_bits(int size);
void	ft_sort_radix(t_stack *a, t_stack *b, t_bench *bench);
double	ft_disorder_index(t_stack *stack);
int		ft_is_sorted(t_stack *stack);
int		ft_chunk_size(int n);
int		ft_max_position(t_stack *stack);
void	ft_push_chunks(t_stack *a, t_stack *b, int chunk_size, t_bench *bench);
void	ft_sort_chunks(t_stack *a, t_stack *b, t_bench *bench);
int		ft_get_strategy(char *arg);
void	ft_dispatch(t_stack *a, t_stack *b, t_bench *bench, int strategy);
void	ft_dispatch_adaptive(t_stack *a, t_stack *b, t_bench *bench);
void	ft_init_bench(t_bench *bench, t_stack *a, int *active);
void	ft_print_disorder(double disorder);
void	ft_print_strategy(t_bench *bench);
void	ft_print_bench(t_bench *bench);
void	ft_print_total(t_bench *bench);
void	ft_print_pair(char *name, int value);
void	ft_print_count(t_bench *bench);
int		ft_get_flag(char **argv, int *active, int *start);
int		ft_check_no_flag(int first, int *start);
int		ft_flag_single(int first, int *active, int *start);
int		ft_flag_double(int first, int second, int *active, int *start);
int		ft_prepare_stack(t_stack *a, char **argv, int strategy, int start);
void	ft_sort_minors(t_stack *a, t_stack *b, t_bench *bench);
void	ft_sort_three(t_stack *a, t_bench *bench);

#endif
