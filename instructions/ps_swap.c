#include "instructions_ps.h"

/*
** These functions acts on stack A & stack B.
** They swap the topmost values of their stack.
*/

void	ps_sa(t_two_stacks *s)
{
	int	tmp;

	if (s->top_a < 1)
		return ;
	tmp = s->array[s->top_a];
	s->array[s->top_a] = s->array[s->top_a - 1];
	s->array[s->top_a - 1] = tmp;
}

void	ps_sb(t_two_stacks *s)
{
	int	tmp;

	if (s->top_b > s->stack_size - 2)
		return ;
	tmp = s->array[s->top_b];
	s->array[s->top_b] = s->array[s->top_b + 1];
	s->array[s->top_b + 1] = tmp;
}

void	ps_ss(t_two_stacks *s)
{
	ps_sa(s);
	ps_sb(s);
}
