#include "push_swap.h"

int	is_b_empty(t_two_stacks *s)
{
	return ((s->top_b == s->stack_size));
}

int	is_a_empty(t_two_stacks *s)
{
	return ((s->top_a == -1));
}

long	ft_diff(int a, int b)
{
	long	diff;

	diff = (long)a - (long)b;
	if (diff < 0)
		diff *= -1;
	return (diff);
}

int	ft_less(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int	ft_more(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
