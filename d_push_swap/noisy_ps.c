#include "push_swap.h"

int	n_sa(t_two_stacks *s)
{
	ft_putstr_fd("sa\n", 1);
	ps_sa(s);
	return (1);
}

int	n_sb(t_two_stacks *s)
{
	ft_putstr_fd("sb\n", 1);
	ps_sb(s);
	return (1);
}

int	n_ss(t_two_stacks *s)
{
	ft_putstr_fd("ss\n", 1);
	ps_ss(s);
	return (1);
}
