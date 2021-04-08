#include "push_swap.h"

int	n_ra(t_two_stacks *s)
{
	ft_putstr_fd("ra\n", 1);
	ps_ra(s);
	return (1);
}

int	n_rb(t_two_stacks *s)
{
	ft_putstr_fd("rb\n", 1);
	ps_rb(s);
	return (1);
}

int	n_rr(t_two_stacks *s)
{
	ft_putstr_fd("rr\n", 1);
	ps_rr(s);
	return (1);
}
