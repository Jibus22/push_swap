#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_two_stacks	*stack;

	stack = init_stack(ac, av);
	if (!stack)
		return (1);
	if (stack->stack_size == 1)
		;
	else if (stack->stack_size == 2)
		sort_two(stack);
	else if (stack->stack_size == 3)
		sort_three_a(stack);
	else if (stack->stack_size == 4)
		sort_four(stack);
	else if (stack->stack_size == 5)
		sort_five(stack);
	else
		algo_v5(stack);
	return (0);
}

/*
** ft_print_two_stacks(stack);
*/
