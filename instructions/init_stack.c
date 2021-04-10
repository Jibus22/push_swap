/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 01:35:07 by user42            #+#    #+#             */
/*   Updated: 2021/04/11 01:36:44 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions_ps.h"

t_two_stacks	*init_stack(int ac, char *av[])
{
	t_two_stacks	*stack;
	int				*arr;
	int				size_array;

	if (ac < 2)
		return (NULL);
	size_array = ac - 1;
	stack = ft_create_two_stacks(ac - 1);
	if (!stack)
		return (NULL);
	arr = convert_argv_to_int_array(size_array, av);
	if (!arr)
	{
		ft_free_two_stacks(stack);
		return (NULL);
	}
	if (check_duplicates(arr, size_array) == -1)
	{
		ft_free_two_stacks(stack);
		free(arr);
		return (NULL);
	}
	fill_stack_with_int_array(stack, arr, size_array);
	free(arr);
	return (stack);
}

/*
**	printf("stacksize : %d\ttop_a: %d\ttop_b: %d\n", \
**	stack->stack_size, stack->top_a, stack->top_b);
**	ft_print_two_stacks(stack);
*/
