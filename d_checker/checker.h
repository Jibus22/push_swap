#ifndef CHECKER_H
# define CHECKER_H

# include "instructions_ps.h"
# include "libft.h"

/*
** instructions magic numbers
*/

# define PS_SA 1
# define PS_SB 2
# define PS_SS 3
# define PS_PA 4
# define PS_PB 5
# define PS_RA 6
# define PS_RB 7
# define PS_RR 8
# define PS_RRA 9
# define PS_RRB 10
# define PS_RRR 11

/*
** main checker functions
*/

int		execute_instructions(t_list *instructions, t_two_stacks *s);
int		verify_instructions(t_list *instructions);
void	check_stacks(t_two_stacks *s);
void	execute_it(t_two_stacks *s, int code);
int		which_instruction(char *instr);

#endif
