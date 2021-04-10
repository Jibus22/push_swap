/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_v5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 01:23:53 by user42            #+#    #+#             */
/*   Updated: 2021/04/11 01:23:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	select_shortest_mv(t_moves *tmp, t_moves *above)
{
	if (above->init == 0)
	{
		move_cpy(tmp, above);
		return (0);
	}
	if (above->total_moves > tmp->total_moves)
		move_cpy(tmp, above);
	return (0);
}

int	best_move_a_to_b(t_two_stacks *s, t_moves *best)
{
	t_moves	tmp;
	int		index;

	init_move(best);
	index = s->top_a + 1;
	while (--index > -1)
	{
		set_move(s, &tmp, index);
		select_shortest_mv(&tmp, best);
	}
	return (0);
}

int	execute_best_move(t_two_stacks *s, t_moves *best)
{
	int	i;

	if (best->init == 0)
	{
		n_pb(s);
		return (0);
	}
	i = best->common_moves;
	while (i-- > 0)
		execute_n_ps(s, best->common_way);
	i = best->moves_b;
	while (i-- > 0)
		execute_n_ps(s, best->way_b);
	i = best->moves_a;
	while (i-- > 0)
		execute_n_ps(s, best->way_a);
	n_pb(s);
	if (best->way_b_after)
		n_rb(s);
	return (0);
}

int	algo_v5(t_two_stacks *s)
{
	t_moves	best;

	while (!is_a_empty(s))
	{
		best_move_a_to_b(s, &best);
		execute_best_move(s, &best);
	}
	full_a_v2(s);
	return (0);
}

/*
** ft_print_two_stacks(s);
** print_mv(best);
*/
