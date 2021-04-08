#include "push_swap.h"

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

//La c'est différent, on doit trouver la valeur supérieure la plus proche
//et la mettre au bottom (et non au top)
int	find_place_in_b_to_small_a_value(t_two_stacks *s, t_moves *tmp, int value)
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

//Looking for a value in B which is smaller than value. Keeping the nearest of
//theses.
//If they doesn't exist, value is the smaller so result should be PB-RB
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
		find_place_in_b_to_small_a_value(s, tmp, value);
	else
		set_b_way_top(s, tmp);
	return (0);
}

int	set_a_way(t_two_stacks *s, t_moves *tmp)
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

int	set_common_moves(t_moves *tmp)
{
	if (tmp->way_a == N_RA && tmp->way_b == N_RB)
	{
		tmp->common_way = N_RR;
		tmp->common_moves = ft_less(tmp->moves_a, tmp->moves_b);
		tmp->moves_a -= tmp->common_moves;
		tmp->moves_b -= tmp->common_moves;
		tmp->total_moves = tmp->common_moves + ft_more(tmp->moves_a, tmp->moves_b);
	}
	else if (tmp->way_a == N_RRA && tmp->way_b == N_RRB)
	{
		tmp->common_way = N_RRR;
		tmp->common_moves = ft_less(tmp->moves_a, tmp->moves_b);
		tmp->moves_a -= tmp->common_moves;
		tmp->moves_b -= tmp->common_moves;
		tmp->total_moves = tmp->common_moves + ft_more(tmp->moves_a, tmp->moves_b);
	}
	else
		tmp->total_moves = tmp->moves_a + tmp->moves_b;
	if (tmp->way_b_after)
		tmp->total_moves += 1;
	return (0);
}

int	set_move(t_two_stacks *s, t_moves *tmp, int index)
{
	init_move(tmp);
	tmp->init = 1;
	seek_place_in_b_for_a_value(s, tmp, s->array[index]);
	tmp->index_a = index;
	set_a_way(s, tmp);
	set_common_moves(tmp);
	return (0);
}

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

int	best_move_a_to_b(t_two_stacks *s, t_moves *best, int max_mv)
{
	t_moves tmp;
	int		index;

	index = s->top_a + 1;
	while (--index > -1)
	{
		set_move(s, &tmp, index);
		if (tmp.total_moves <= max_mv)
			select_shortest_mv(&tmp, best);
	}
	return (0);
}

int	seek_best_move(t_two_stacks *s, t_moves *best,int max_mv)
{
	init_move(best);
	best_move_a_to_b(s, best, max_mv);
	return (0);
}

int	execute_best_move(t_two_stacks *s, t_moves *best)
{
	int	i;

	//ft_print_two_stacks(s);
	//print_mv(best);
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
	t_moves best;
	int		max_mv;

	max_mv = s->stack_size * 8 / 100;
	if (max_mv < 2)
		max_mv += 1;
	while (!is_a_empty(s))
	{
		seek_best_move(s, &best, max_mv);
		execute_best_move(s, &best);
	}
	full_a(s);
	//ft_print_two_stacks(s);
	return (0);
}
