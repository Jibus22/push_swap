#include "push_swap.h"

/*
** These functions take double stack (A & B) & t_moves struct as parameter
** They return nothing (0)...
** They find the shortest way to set the right index in the structure to top
** of B, bottom of B, or top of A.
**
** The way is the instruction used to achieve the wanted operation. It can
** be a rotation or a reverse rotation. It will depend of the shortest moves.
** So the number of operation is also set up in structure into
** moves_b/a variable.
*/

int	set_b_way_bottom(t_two_stacks *s, t_moves *tmp)
{
	int	move_r;
	int	move_rr;

	move_r = tmp->index_b - s->top_b + 1;
	move_rr = (s->stack_size - 1) - tmp->index_b;
	if (move_r < move_rr)
	{
		tmp->moves_b = move_r;
		tmp->way_b = N_RB;
	}
	else
	{
		tmp->moves_b = move_rr;
		tmp->way_b = N_RRB;
	}
	tmp->way_b_after = N_RB;
	return (0);
}

int	set_b_way_top(t_two_stacks *s, t_moves *tmp)
{
	int	move_r;
	int	move_rr;

	move_r = tmp->index_b - s->top_b;
	move_rr = s->stack_size - tmp->index_b;
	if (move_r < move_rr)
	{
		tmp->moves_b = move_r;
		tmp->way_b = N_RB;
	}
	else
	{
		tmp->moves_b = move_rr;
		tmp->way_b = N_RRB;
	}
	return (0);
}

int	set_a_way_top(t_two_stacks *s, t_moves *tmp)
{
	int	move_r;
	int	move_rr;

	move_r = s->top_a - tmp->index_a;
	move_rr = tmp->index_a + 1;
	if (move_r < move_rr)
	{
		tmp->moves_a = move_r;
		tmp->way_a = N_RA;
	}
	else
	{
		tmp->moves_a = move_rr;
		tmp->way_a = N_RRA;
	}
	return (0);
}
