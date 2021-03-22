#include "instructions_ps.h"

/*
** pa : push a - take the first element at the top of b and put it at
** the top of a. Do nothing if b is empty.
*/

void	ps_pa(t_two_stacks *s)
{
	int	poped;

	if (s->top_b == s->stack_size)
		return ;
	poped = ft_pop_b(s);
	ft_push_a(s, poped);
}

void	ps_pb(t_two_stacks *s)
{
	int	poped;

	if (s->top_a == -1)
		return ;
	poped = ft_pop_a(s);
	ft_push_b(s, poped);
}
