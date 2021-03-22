#include "instructions_ps.h"

int	ft_pop_a(t_two_stacks *s)
{
	int	poped;

	if (s->top_a < 0)
	{
		ft_putstr_fd("two_stacks error: pop_a underflow\n", 2);
		return (-1);
	}
	poped = s->array[s->top_a];
	s->top_a -= 1;
	return (poped);
}
