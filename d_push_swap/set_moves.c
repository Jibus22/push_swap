#include "push_swap.h"

/*
** Once all necessary moves in A & B had been set up into t_moves struct
** this function check if there is some twins moves. If there is, it will
** set up the corresponding common moves with the twins instructions (rr, rrr).
** 
** For example, instead of doing rb rb & ra ra, we can now do rr rr. This lead
** us in this example to use only 2 instructions instead of 4.
*/

int	set_common_moves(t_moves *tmp)
{
	if (tmp->way_a == N_RA && tmp->way_b == N_RB)
	{
		tmp->common_way = N_RR;
		tmp->common_moves = ft_less(tmp->moves_a, tmp->moves_b);
		tmp->moves_a -= tmp->common_moves;
		tmp->moves_b -= tmp->common_moves;
		tmp->total_moves = tmp->common_moves
			+ ft_more(tmp->moves_a, tmp->moves_b);
	}
	else if (tmp->way_a == N_RRA && tmp->way_b == N_RRB)
	{
		tmp->common_way = N_RRR;
		tmp->common_moves = ft_less(tmp->moves_a, tmp->moves_b);
		tmp->moves_a -= tmp->common_moves;
		tmp->moves_b -= tmp->common_moves;
		tmp->total_moves = tmp->common_moves
			+ ft_more(tmp->moves_a, tmp->moves_b);
	}
	else
		tmp->total_moves = tmp->moves_a + tmp->moves_b;
	if (tmp->way_b_after)
		tmp->total_moves += 1;
	return (0);
}

/*
** Parameters :
**	- s		__double stack.
**	- tmp	__t_moves structure to fullfill. Say which moves in A & B has to
**				been done according to one index & it's corresponding value.
**	- index	__index of stack A which refer to the value we want to insert into
**				stack B.
*/

int	set_move(t_two_stacks *s, t_moves *tmp, int index)
{
	init_move(tmp);
	tmp->init = 1;
	seek_place_in_b_for_a_value(s, tmp, s->array[index]);
	tmp->index_a = index;
	set_a_way_top(s, tmp);
	set_common_moves(tmp);
	return (0);
}
