/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smaller_bigger.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 01:26:09 by user42            #+#    #+#             */
/*   Updated: 2021/04/11 01:26:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	index_smallest_a(t_two_stacks *s)
{
	int	i;
	int	top;
	int	small;

	top = s->top_a + 1;
	small = s->array[top - 1];
	i = top - 1;
	while (--top >= 0)
	{
		if (s->array[top] < small)
		{
			small = s->array[top];
			i = top;
		}
	}
	return (i);
}

int	index_biggest_a(t_two_stacks *s)
{
	int	i;
	int	top;
	int	big;

	top = s->top_a + 1;
	big = s->array[top - 1];
	i = top - 1;
	while (--top >= 0)
	{
		if (s->array[top] > big)
		{
			big = s->array[top];
			i = top;
		}
	}
	return (i);
}

int	get_bigger_a(t_two_stacks *stack)
{
	int	big;
	int	i;

	if (stack->top_a == -1)
		return (0);
	i = 0;
	big = stack->array[i];
	while (++i <= stack->top_a)
		if (stack->array[i] > big)
			big = stack->array[i];
	return (big);
}

int	get_smaller_a(t_two_stacks *stack)
{
	int	small;
	int	i;

	if (stack->top_a == -1)
		return (0);
	i = 0;
	small = stack->array[i];
	while (++i <= stack->top_a)
		if (stack->array[i] < small)
			small = stack->array[i];
	return (small);
}
