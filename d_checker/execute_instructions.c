#include "checker.h"

int	which_instruction(char *instr)
{
	char	*name[12];
	int		code;
	int		i;

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
	i = -1;
	code = 0;
	while (name[++i])
		if (++code && ft_strcmp(name[i], instr) == 0)
			return (code);
	return (-1);
}

void	execute_it(t_two_stacks *s, int code)
{
	if (code == PS_SA)
		ps_sa(s);
	else if (code == PS_SB)
		ps_sb(s);
	else if (code == PS_SS)
		ps_ss(s);
	else if (code == PS_PA)
		ps_pa(s);
	else if (code == PS_PB)
		ps_pb(s);
	else if (code == PS_RA)
		ps_ra(s);
	else if (code == PS_RB)
		ps_rb(s);
	else if (code == PS_RR)
		ps_rr(s);
	else if (code == PS_RRA)
		ps_rra(s);
	else if (code == PS_RRB)
		ps_rrb(s);
	else
		ps_rrr(s);
}

int	execute_instructions(t_list *instructions, t_two_stacks *s)
{
	int	instruct_code;

	if (verify_instructions(instructions) == -1)
		return (-1);
	while (instructions)
	{
		instruct_code = which_instruction((char *)instructions->content);
		if (instruct_code == -1)
		{
			ft_putstr_fd("Error\n", 2);
			return (-1);
		}
		execute_it(s, instruct_code);
		instructions = instructions->next;
	}
	return (0);
}

/*
** ft_print_two_stacks(s);
*/
