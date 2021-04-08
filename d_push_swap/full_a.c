#include "push_swap.h"

int	init_full_a(t_two_stacks *s)
{
	n_pa(s);
	n_pa(s);
	if (s->array[s->top_a] > s->array[0])
		n_sa(s);
	return (0);
}

int	find_nearest_gvalue_in_a_from_value(t_two_stacks *s, int value)
{
	int		index;
	int		top;
	long	smaller_diff;
	long	diff;

	index = -2;
	smaller_diff = LONG_MAX;
	top = s->top_a;
	while (top > -1)
	{
		if (s->array[top] > value)
		{
			diff = ft_diff(s->array[top], value);
			if (diff < smaller_diff)
			{
				smaller_diff = diff;
				index = top;
			}
		}
		top--;
	}
	return (index);
}

int	shortest_way_to_put_index_to_top_a(t_two_stacks *s, int index_a,
			int *way, int *moves)
{
	int	move_r;
	int	move_rr;

	move_r = s->top_a - index_a;
	move_rr = index_a + 1;
	if (move_r < move_rr)
	{
		*moves = move_r;
		*way = N_RA;
	}
	else
	{
		*moves = move_rr;
		*way = N_RRA;
	}
	return (0);
}

int	full_a(t_two_stacks *s)
{
	int	index;
	int	i;
	int	way;

	init_full_a(s);
	while (!is_b_empty(s))
	{
		if (s->array[s->top_a] > s->array[s->top_b])
		{
			while (s->array[0] > s->array[s->top_b]
				&& s->array[0] < s->array[s->top_a])
				n_rra(s);
			n_pa(s);
		}
		if (s->array[s->top_a] < s->array[s->top_b])
		{
			index = find_nearest_gvalue_in_a_from_value(s, s->array[s->top_b]);
			if (index == -2)
				index = index_smallest_a(s);
			shortest_way_to_put_index_to_top_a(s, index, &way, &i);
			while (i-- > 0)
				execute_n_ps(s, way);
			n_pa(s);
		}
	}
	index = index_smallest_a(s);
	shortest_way_to_put_index_to_top_a(s, index, &way, &i);
	while (i-- > 0)
		execute_n_ps(s, way);
	return (0);
}
