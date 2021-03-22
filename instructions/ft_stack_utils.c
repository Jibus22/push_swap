#include "instructions_ps.h"

void	ft_free_two_stacks(t_two_stacks *s)
{
	free(s->array);
	free(s);
}

void	ft_print_two_stacks(t_two_stacks *s)
{
	int	i;

	i = 0;
	printf("\e[1;13m-------print_____stacks------\e[0m\n");
	while (i <= s->top_a)
	{
		printf("stack_a value[%-3d]: %4d\n", i, s->array[i]);
		i++;
	}
	i = s->stack_size - 1;
	while (i >= s->top_b)
	{
		printf("stack_b value[%-3d]: %4d\n", i, s->array[i]);
		i--;
	}
	printf("\n");
	fflush(stdout);
}
