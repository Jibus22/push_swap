#include "instructions_ps.h"

void	fill_stack_with_int_array(t_two_stacks *s, int *array, int size)
{
	int	i;

	i = size - 1;
	while (i >= 0)
	{
		ft_push_a(s, array[i]);
		i--;
	}
}
