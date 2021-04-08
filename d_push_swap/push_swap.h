#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "instructions_ps.h"
# include "libft.h"

/*
** instructions magic numbers
*/

# define N_SA 1
# define N_SB 2
# define N_SS 3
# define N_PA 4
# define N_PB 5
# define N_RA 6
# define N_RB 7
# define N_RR 8
# define N_RRA 9
# define N_RRB 10
# define N_RRR 11
# define ALGO_S3 12

/*
** push_swap structure
*/

typedef struct s_moves
{
	int	init;
	int	index_a;
	int	way_a;
	int	moves_a;
	int	index_b;
	int	way_b;
	int way_b_after;
	int	moves_b;
	int common_moves;
	int	common_way;
	int total_moves;
}	t_moves;

/*
** push_swap algos
*/

int			sort_two(t_two_stacks *s);
void		sort_three_a(t_two_stacks *s);
void		sort_four(t_two_stacks *s);
void		sort_five(t_two_stacks *s);
int			switch_bth_a(t_two_stacks *s);
void		execute_n_ps(t_two_stacks *s, int code);

long		ft_diff(int a, int b);
int			ft_less(int a, int b);
int			ft_more(int a, int b);
int			is_a_sorted(t_two_stacks *s, int min, int max);

int			algo_v5(t_two_stacks *s);
int			move_cpy(t_moves *src, t_moves *dst);
void		init_move(t_moves *mv);
void		print_mv(t_moves *mv);
int			full_a(t_two_stacks *s);

/*
** tools
*/

int			index_biggest_a(t_two_stacks *s);
int			index_smallest_a(t_two_stacks *s);
int			get_bigger_a(t_two_stacks *stack);
int			get_smaller_a(t_two_stacks *stack);
int			is_b_empty(t_two_stacks *s);
int			is_a_empty(t_two_stacks *s);

/*
** Noisy push_swap instructions
*/

int			n_sa(t_two_stacks *s);
int			n_sb(t_two_stacks *s);
int			n_ss(t_two_stacks *s);
int			n_pa(t_two_stacks *s);
int			n_pb(t_two_stacks *s);
int			n_ra(t_two_stacks *s);
int			n_rb(t_two_stacks *s);
int			n_rr(t_two_stacks *s);
int			n_rra(t_two_stacks *s);
int			n_rrb(t_two_stacks *s);
int			n_rrr(t_two_stacks *s);

#endif
