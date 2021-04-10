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
	int	way_b_after;
	int	moves_b;
	int	common_moves;
	int	common_way;
	int	total_moves;
}	t_moves;

/*
** push_swap algos short stack
*/

int			sort_two(t_two_stacks *s);
void		sort_three_a(t_two_stacks *s);
void		sort_four(t_two_stacks *s);
void		sort_five(t_two_stacks *s);
int			switch_bth_a(t_two_stacks *s);

/*
** push_swap algos long stack
*/

int			algo_v5(t_two_stacks *s);
int			set_b_way_bottom(t_two_stacks *s, t_moves *tmp);
int			set_b_way_top(t_two_stacks *s, t_moves *tmp);
int			set_a_way_top(t_two_stacks *s, t_moves *tmp);
int			seek_place_in_b_for_a_value(t_two_stacks *s, t_moves *tmp, int val);
int			set_move(t_two_stacks *s, t_moves *tmp, int index);
int			full_a_v2(t_two_stacks *s);

/*
** utils algo
*/

void		execute_n_ps(t_two_stacks *s, int code);
int			is_b_empty(t_two_stacks *s);
int			is_a_empty(t_two_stacks *s);
int			is_a_sorted(t_two_stacks *s, int min, int max);

/*
** utils move
*/

void		init_move(t_moves *mv);
int			move_cpy(t_moves *src, t_moves *dst);
void		print_mv(t_moves *mv);

/*
** utils
*/

long		ft_diff(int a, int b);
int			ft_less(int a, int b);
int			ft_more(int a, int b);
int			is_stack_sorted(t_two_stacks *s);

/*
** other utils
*/

int			index_biggest_a(t_two_stacks *s);
int			index_smallest_a(t_two_stacks *s);
int			get_bigger_a(t_two_stacks *stack);
int			get_smaller_a(t_two_stacks *stack);

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
