#include "push_swap.h"

int	main(int ac, char *av[])
{
	//t_list			*instructions;
	t_two_stacks	*stack;
	//int				ret;

	stack = init_stack(ac, av);
	if (!stack)
		return (1);
	ft_print_two_stacks(stack);
}
