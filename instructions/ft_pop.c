/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 01:34:42 by user42            #+#    #+#             */
/*   Updated: 2021/04/11 01:34:43 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions_ps.h"

int	ft_pop_a(t_two_stacks *s)
{
	int	poped;

	if (s->top_a < 0)
	{
		ft_putstr_fd("two_stacks error: pop_a underflow\n", 2);
		return (-1);
	}
	poped = s->array[s->top_a];
	s->top_a -= 1;
	return (poped);
}

int	ft_pop_b(t_two_stacks *s)
{
	int	poped;

	if (s->top_b > s->stack_size - 1)
	{
		ft_putstr_fd("two_stacks error: pop_b underflow\n", 2);
		return (-1);
	}
	poped = s->array[s->top_b];
	s->top_b += 1;
	return (poped);
}
