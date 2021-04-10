/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 01:26:16 by user42            #+#    #+#             */
/*   Updated: 2021/04/11 01:26:32 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	shortest_way_to_top_a(int small, int *i, int size)
{
	int	way;
	int	half;

	half = size / 2;
	if (small < half)
	{
		way = N_RRA;
		*i = small + 1;
	}
	else
	{
		way = N_RA;
		*i = size - (small + 1);
	}
	return (way);
}

void		sort_five(t_two_stacks *s)
{
	int	index;
	int	way;
	int	i;

	i = 0;
	index = index_smallest_a(s);
	way = shortest_way_to_top_a(index, &i, 5);
	while (i--)
		execute_n_ps(s, way);
	n_pb(s);
	i = 0;
	index = index_smallest_a(s);
	way = shortest_way_to_top_a(index, &i, 4);
	while (i--)
		execute_n_ps(s, way);
	n_pb(s);
	sort_three_a(s);
	n_pa(s);
	n_pa(s);
}

void		sort_four(t_two_stacks *s)
{
	int	small;
	int	way;
	int	i;

	i = 0;
	small = index_smallest_a(s);
	way = shortest_way_to_top_a(small, &i, 4);
	while (i)
	{
		execute_n_ps(s, way);
		i--;
	}
	n_pb(s);
	sort_three_a(s);
	n_pa(s);
}
