/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_two_stacks.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 01:34:31 by user42            #+#    #+#             */
/*   Updated: 2021/04/11 01:34:32 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions_ps.h"

t_two_stacks	*ft_create_two_stacks(unsigned int stacksize)
{
	t_two_stacks	*stack;

	if (!stacksize)
		return (NULL);
	stack = (t_two_stacks *)malloc(sizeof(*stack));
	if (!stack)
		return (NULL);
	stack->array = (int *)malloc(sizeof(*(stack->array)) * stacksize);
	if (!stack->array)
	{
		free(stack);
		return (NULL);
	}
	ft_memset(stack->array, 0, sizeof(char));
	stack->top_a = -1;
	stack->top_b = stacksize;
	stack->stack_size = stacksize;
	return (stack);
}
