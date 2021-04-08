#include "checker.h"

static void	ps_error()
{
	ft_putstr_fd("KO\n", 1);
	return ;
}

static void	ps_success()
{
	ft_putstr_fd("OK\n", 1);
	return ;
}

void	check_stacks(t_two_stacks *s)
{
	int	i;

	if (s->top_b < s->stack_size)
		return (ps_error());
	i = s->top_a;
	while (i > 0)
	{
		if (s->array[i] > s->array[i - 1])
			return (ps_error());
		i--;
	}
	return (ps_success());
}
