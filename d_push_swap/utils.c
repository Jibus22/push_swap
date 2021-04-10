/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 01:26:58 by user42            #+#    #+#             */
/*   Updated: 2021/04/11 01:27:18 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_b_empty(t_two_stacks *s)
{
	return ((s->top_b == s->stack_size));
}

int		is_a_empty(t_two_stacks *s)
{
	return ((s->top_a == -1));
}

long	ft_diff(int a, int b)
{
	long	diff;

	diff = (long)a - (long)b;
	if (diff < 0)
		diff *= -1;
	return (diff);
}

int		ft_less(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int		ft_more(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
