/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_a_v2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 01:24:24 by user42            #+#    #+#             */
/*   Updated: 2021/04/11 01:24:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Look for the greatest value in stack B and return its index.
*/

int	seek_greater_value_in_b(t_two_stacks *s)
{
	int	i;
	int	value;
	int	gv_index;

	i = s->top_b;
	gv_index = i;
	value = s->array[i];
	while (i < s->stack_size)
	{
		if (s->array[i] > value)
		{
			value = s->array[i];
			gv_index = i;
		}
		i++;
	}
	return (gv_index);
}

/*
** Set the shortest way in B to put the value pointed by gv_index_b to top of B.
*/

int	shortest_way_to_top_b(t_two_stacks *s, int gv_index_b, int *way, int *moves)
{
	int	move_r;
	int	move_rr;

	move_r = gv_index_b - s->top_b;
	move_rr = s->stack_size - gv_index_b;
	if (move_r < move_rr)
	{
		*moves = move_r;
		*way = N_RB;
	}
	else
	{
		*moves = move_rr;
		*way = N_RRB;
	}
	return (0);
}

/*
** As B is already sorted, the only thing to do here is to bring back the
** greatest value from B to the top by the shortest way to then push it all
** to A.
** The sequence is descending in B and by this way will be ascending in A.
*/

int	full_a_v2(t_two_stacks *s)
{
	int	gv_index_b;
	int	moves;
	int	way;

	gv_index_b = seek_greater_value_in_b(s);
	shortest_way_to_top_b(s, gv_index_b, &way, &moves);
	while (moves-- > 0)
		execute_n_ps(s, way);
	while (!is_b_empty(s))
		n_pa(s);
	return (0);
}
