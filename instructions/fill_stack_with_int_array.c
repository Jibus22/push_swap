/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_with_int_array.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 01:34:21 by user42            #+#    #+#             */
/*   Updated: 2021/04/11 01:34:22 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions_ps.h"

void	fill_stack_with_int_array(t_two_stacks *s, int *array, int size)
{
	int	i;

	i = size;
	while (i-- > 0)
		ft_push_a(s, array[i]);
}
