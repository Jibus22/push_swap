#include "instructions_ps.h"

int	ft_pop_b(t_two_stacks *s)
{
	int	poped;

	if (s->top_b > s->stack_size - 1)
	{
		ft_putstr_fd("two_stacks error: pop_b underflow\n", 2);
		return (-1);
	}
	poped = s->array[s->top_b];
	s->top_b += 1;
	return (poped);
}
