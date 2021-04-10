/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 01:19:28 by user42            #+#    #+#             */
/*   Updated: 2021/04/11 01:21:21 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ps_error(void)
{
	ft_putstr_fd("KO\n", 1);
	return ;
}

static void	ps_success(void)
{
	ft_putstr_fd("OK\n", 1);
	return ;
}

void		check_stacks(t_two_stacks *s)
{
	int	i;

	if (s->top_b < s->stack_size)
		return (ps_error());
	i = s->top_a;
	while (i > 0)
	{
		if (s->array[i] > s->array[i - 1])
			return (ps_error());
		i--;
	}
	return (ps_success());
}
