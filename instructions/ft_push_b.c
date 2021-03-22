#include "instructions_ps.h"

int	ft_push_b(t_two_stacks *s, int value)
{
	if (s->top_b > (s->top_a + 1))
	{
		s->top_b -= 1;
		s->array[s->top_b] = value;
	}
	else
	{
		ft_putstr_fd("two_stacks error: push_b overflow\n", 2);
		return (-1);
	}
	return (0);
}
