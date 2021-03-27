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
		return (NULL);
	if (check_duplicates(arr, size_array) == -1)
	{
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
**
*/
