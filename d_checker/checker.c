#include "checker.h"

void	clear_instructions(void *content)
{
	free((char *)content);
}

static int	add_instruction_to_list(t_list **head, char *line)
{
	t_list	*new;

	new = ft_lstnew(line);
	if (!new)
		return (-1);
	ft_lstadd_back(head, new);
	return (0);
}

static t_list	*loop(t_two_stacks *s)
{
	t_list	*instructions;
	char	*line;
	int		ret;

	instructions = NULL;
	while (1)
	{
		ret = get_next_line(0, &line);
		if (ret < 0 || !*line)
			break ;
		if (add_instruction_to_list(&instructions, line) == -1)
		{
			free(line);
			ft_lstclear(&instructions, &clear_instructions);
			return (NULL);
		}
		//execute_it(s, which_instruction(line));
		//ft_print_two_stacks(s);
	}
	free(line);
	(void)s;
	return (instructions);
}

int	main(int ac, char *av[])
{
	t_list			*instructions;
	t_two_stacks	*stack;
	int				ret;

	stack = init_stack(ac, av);
	if (!stack)
		return (1);
	//ft_print_two_stacks(stack);
	instructions = loop(stack);
	if (!instructions)
		return (1);
	ret = 0;
	ret = execute_instructions(instructions, stack);
	if (ret != -1)
		check_stacks(stack);
	ft_lstclear(&instructions, &clear_instructions);
	ft_free_two_stacks(stack);
	//system("leaks checker");
	return (0);
}
