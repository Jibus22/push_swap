#include "checker.h"

int	main(int ac, char *av[])
{
	t_two_stacks	*stack;
	int				*array;

	if (ac < 2)
	{
		printf("%s error: at least one argument needed.\n", *av);
		return (1);
	}
	stack = ft_create_two_stacks(ac);
	array = convert_argv_to_int_array(ac - 1, av);
	fill_stack_with_int_array(stack, array, ac - 1);
	free(array);
	printf("stacksize : %d\ttop_a: %d\ttop_b: %d\n", \
	stack->stack_size, stack->top_a, stack->top_b);
	ft_print_two_stacks(stack);
	ft_free_two_stacks(stack);
	return (0);
}
