#include "push_swap.h"

/*
** Seek in stack B the nearest value from received value parameter which is
** greater than it.
** the stack index of this value is recorded in t_moves struct.
** In the algorithm logic, when we deal with a greater value we need it to
** the bottom of B before pushing topA to topB then rotate to create the
** right sequence.
*/

int	seek_place_in_b_to_small_a_value(t_two_stacks *s, t_moves *tmp, int value)
{
	long	smaller_diff;
	long	diff;
	int		i;

	i = s->top_b;
	smaller_diff = LONG_MAX;
	while (i < s->stack_size)
	{
		if (s->array[i] > value)
		{
			diff = ft_diff(s->array[i], value);
			if (diff < smaller_diff)
			{
				smaller_diff = diff;
				tmp->index_b = i;
			}
		}
		i++;
	}
	set_b_way_bottom(s, tmp);
	return (0);
}

/*
** Seek in stack B the nearest value from received value parameter which is
** smaller than it.
** the stack index of this value is recorded in t_moves struct.
** In the algorithm logic, when we deal with a smaller value we need it to
** the top of B before pushing topA to topB to create the right sequence.
*/

int	seek_place_in_b_for_a_value(t_two_stacks *s, t_moves *tmp, int value)
{
	long	smaller_diff;
	long	diff;
	int		i;

	i = s->top_b;
	smaller_diff = LONG_MAX;
	while (i < s->stack_size)
	{
		if (s->array[i] < value)
		{
			diff = ft_diff(s->array[i], value);
			if (diff < smaller_diff)
			{
				smaller_diff = diff;
				tmp->index_b = i;
			}
		}
		i++;
	}
	if (smaller_diff == LONG_MAX)
		seek_place_in_b_to_small_a_value(s, tmp, value);
	else
		set_b_way_top(s, tmp);
	return (0);
}
