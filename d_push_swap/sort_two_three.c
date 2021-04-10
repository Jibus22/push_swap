#include "push_swap.h"

int	switch_bth_a(t_two_stacks *s)
{
	if (s->array[0] > s->array[s->top_a]
		&& s->array[s->top_a] < s->array[s->top_a - 1])
		n_rra(s);
	if (s->array[0] < s->array[s->top_a]
		&& s->array[s->top_a] > s->array[s->top_a - 1])
	{
		if (s->array[0] < s->array[s->top_a - 1])
			n_sa(s);
		else
			n_ra(s);
	}
	if (s->array[0] < s->array[s->top_a]
		&& s->array[s->top_a] < s->array[s->top_a - 1])
		n_rra(s);
	if (s->array[0] > s->array[s->top_a]
		&& s->array[s->top_a] > s->array[s->top_a - 1])
		n_sa(s);
	return (0);
}

void	sort_three_a(t_two_stacks *s)
{
	while (!(s->array[s->top_a] < s->array[s->top_a - 1]
			&& s->array[s->top_a - 1] < s->array[0]))
		switch_bth_a(s);
}

int	sort_two(t_two_stacks *s)
{
	if (s->array[s->top_a] > s->array[s->top_a - 1])
		n_sa(s);
	return (1);
}
