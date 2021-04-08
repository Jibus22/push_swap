#include "push_swap.h"

void	execute_n_ps(t_two_stacks *s, int code)
{
	if (code == N_SA)
		n_sa(s);
	else if (code == N_SB)
		n_sb(s);
	else if (code == N_SS)
		n_ss(s);
	else if (code == N_PA)
		n_pa(s);
	else if (code == N_PB)
		n_pb(s);
	else if (code == N_RA)
		n_ra(s);
	else if (code == N_RB)
		n_rb(s);
	else if (code == N_RR)
		n_rr(s);
	else if (code == N_RRA)
		n_rra(s);
	else if (code == N_RRB)
		n_rrb(s);
	else
		n_rrr(s);
}
