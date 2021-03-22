#include "instructions_ps.h"

/*
** rotate.
** shift up all elements of stack a/b by 1. The first element becomes
** the last one.
*/

void	ps_ra(t_two_stacks *s)
{
	int	i;
	int	tmp;

	i = s->top_a;
	if (i <= 0)
		return ;
	tmp = s->array[i];
	while (i > 0)
	{
		s->array[i] = s->array[i - 1];
		i--;
	}
	s->array[i] = tmp;
}

void	ps_rb(t_two_stacks *s)
{
	int	i;
	int	tmp;

	i = s->top_b;
	if (i >= s->stack_size - 1)
		return ;
	tmp = s->array[i];
	while (i < s->stack_size - 1)
	{
		s->array[i] = s->array[i + 1];
		i++;
	}
	s->array[i] = tmp;
}

void	ps_rr(t_two_stacks *s)
{
	ps_ra(s);
	ps_rb(s);
}
