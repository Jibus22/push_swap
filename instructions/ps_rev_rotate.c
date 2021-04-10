/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 01:35:52 by user42            #+#    #+#             */
/*   Updated: 2021/04/11 01:35:58 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions_ps.h"

/*
** reverse rotate - shift down all elements of stack a/b by 1. The last
** element becomes the first one.
*/

void	ps_rra(t_two_stacks *s)
{
	int	i;
	int	tmp;

	if (s->top_a <= 0)
		return ;
	i = 0;
	tmp = s->array[i];
	while (i < s->top_a)
	{
		s->array[i] = s->array[i + 1];
		i++;
	}
	s->array[i] = tmp;
}

void	ps_rrb(t_two_stacks *s)
{
	int	i;
	int	tmp;

	if (s->top_b >= s->stack_size - 1)
		return ;
	i = s->stack_size - 1;
	tmp = s->array[i];
	while (i > s->top_b)
	{
		s->array[i] = s->array[i - 1];
		i--;
	}
	s->array[i] = tmp;
}

void	ps_rrr(t_two_stacks *s)
{
	ps_rra(s);
	ps_rrb(s);
}
