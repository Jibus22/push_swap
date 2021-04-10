#include "push_swap.h"

int	is_stack_sorted(t_two_stacks *s)
{
	int	i;

	if (s->top_b < s->stack_size)
		return (0);
	i = s->top_a;
	while (i > 0)
	{
		if (s->array[i] > s->array[i - 1])
			return (0);
		i--;
	}
	return (1);
}
