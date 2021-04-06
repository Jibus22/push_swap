#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_two_stacks	*stack;

	stack = init_stack(ac, av);
	if (!stack)
		return (1);
	//ft_print_two_stacks(stack);
	/*if (stack->stack_size == 2)
		sort_two(stack);
	if (stack->stack_size == 3)
		sort_three_a(stack);
	if (stack->stack_size == 4)
		sort_four(stack);
	if (stack->stack_size == 5)
		sort_five(stack);*/
	/*else
		algo_100(stack);*/
	//else
		algo_v4(stack);
	//ft_print_two_stacks(stack);
	return (0);
}
