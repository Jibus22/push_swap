/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noisy_ps_rev_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 01:25:02 by user42            #+#    #+#             */
/*   Updated: 2021/04/11 01:25:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	n_rrr(t_two_stacks *s)
{
	ft_putstr_fd("rrr\n", 1);
	ps_rrr(s);
	return (1);
}

int	n_rra(t_two_stacks *s)
{
	ft_putstr_fd("rra\n", 1);
	ps_rra(s);
	return (1);
}

int	n_rrb(t_two_stacks *s)
{
	ft_putstr_fd("rrb\n", 1);
	ps_rrb(s);
	return (1);
}
