#include "checker.h"

static t_two_stacks	*init_stack(int ac, char *av[])
{
	t_two_stacks	*stack;
	int				*arr;
	int				size_array;

	if (ac < 2)
	{
		printf("%s error: at least one argument needed.\n", *av);
		return (NULL);
	}
	size_array = ac - 1;
	stack = ft_create_two_stacks(ac + 4);
	if (!stack)
		return (NULL);
	arr = convert_argv_to_int_array(size_array, av);
	fill_stack_with_int_array(stack, arr, size_array);
	free(arr);
	printf("stacksize : %d\ttop_a: %d\ttop_b: %d\n", \
	stack->stack_size, stack->top_a, stack->top_b);
	ft_print_two_stacks(stack);
	return (stack);
}

int	main(int ac, char *av[])
{
	t_two_stacks	*stack;

	stack = init_stack(ac, av);
	if (!stack)
		return (1);
	ft_print_two_stacks(stack);
	ft_free_two_stacks(stack);
	return (0);
}
