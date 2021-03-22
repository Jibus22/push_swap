#include "instructions_ps.h"

int	ft_push_a(t_two_stacks *s, int value)
{
	if (s->top_a < (s->top_b - 1))
	{
		s->top_a += 1;
		s->array[s->top_a] = value;
	}
	else
	{
		ft_putstr_fd("two_stacks error: push_a overflow\n", 2);
		return (-1);
	}
	return (0);
}
