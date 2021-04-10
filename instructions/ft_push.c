/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 01:34:49 by user42            #+#    #+#             */
/*   Updated: 2021/04/11 01:34:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions_ps.h"

int	ft_push_a(t_two_stacks *s, int value)
{
	if (s->top_a < (s->top_b - 1))
	{
		s->top_a += 1;
		s->array[s->top_a] = value;
	}
	else
	{
		ft_putstr_fd("two_stacks error: push_a overflow\n", 2);
		return (-1);
	}
	return (0);
}

int	ft_push_b(t_two_stacks *s, int value)
{
	if (s->top_b > (s->top_a + 1))
	{
		s->top_b -= 1;
		s->array[s->top_b] = value;
	}
	else
	{
		ft_putstr_fd("two_stacks error: push_b overflow\n", 2);
		return (-1);
	}
	return (0);
}
