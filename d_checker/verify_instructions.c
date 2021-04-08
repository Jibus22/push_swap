#include "checker.h"

static int	compare_instructions(t_list *instructions, char *name[])
{
	int	cmp;
	int	i;

	while (instructions)
	{
		i = 0;
		cmp = 1;
		while (name[i])
		{
			cmp = ft_strcmp(name[i], (char *)(instructions->content));
			if (cmp == 0)
				break;
			i++;
		}
		if (cmp)
		{
			ft_putstr_fd("Error\n", 2);
			return (-1);
		}
		instructions = instructions->next;
	}
	return (0);
}

int	verify_instructions(t_list *instructions)
{
	char	*name[12];

	name[0] = "sa";
	name[1] = "sb";
	name[2] = "ss";
	name[3] = "pa";
	name[4] = "pb";
	name[5] = "ra";
	name[6] = "rb";
	name[7] = "rr";
	name[8] = "rra";
	name[9] = "rrb";
	name[10] = "rrr";
	name[11] = NULL;
	if (compare_instructions(instructions, name) == -1)
		return (-1);
	return (0);
}
