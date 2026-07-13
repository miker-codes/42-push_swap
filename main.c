#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (0);
	ft_init_stack(&a);
	ft_init_stack(&b);
	if (!ft_validate_args(argc, argv))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	ft_fill_stack(argc, argv, &a);
	if (ft_has_duplicates(&a))
	{
		ft_free_stack(&a);
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	ft_sort_simple(&a, &b);
	ft_free_stack(&a);
	ft_free_stack(&b);
	return (0);
}