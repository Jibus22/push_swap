#ifndef INSTRUCTIONS_PS_H
# define INSTRUCTIONS_PS_H

# include <stdio.h>
# include "libft.h"

typedef struct s_two_stacks
{
	int	stack_size;
	int	*array;
	int	top_a;
	int	top_b;
}	t_two_stacks;

/*
** Main stack functions
*/

t_two_stacks	*ft_create_two_stacks(unsigned int stacksize);
int				ft_push_a(t_two_stacks *s, int value);
int				ft_push_b(t_two_stacks *s, int value);
int				ft_pop_a(t_two_stacks *s);
int				ft_pop_b(t_two_stacks *s);

void			ft_print_two_stacks(t_two_stacks *s);
void			ft_free_two_stacks(t_two_stacks *s);
int				*convert_argv_to_int_array(int array_size, char *args[]);
void			fill_stack_with_int_array(t_two_stacks *s,
					int *array, int size);

/*
** Push_swap instructions
*/

void			ps_sa(t_two_stacks *s);
void			ps_sb(t_two_stacks *s);
void			ps_ss(t_two_stacks *s);
void			ps_pa(t_two_stacks *s);
void			ps_pb(t_two_stacks *s);
void			ps_ra(t_two_stacks *s);
void			ps_rb(t_two_stacks *s);
void			ps_rr(t_two_stacks *s);
void			ps_rra(t_two_stacks *s);
void			ps_rrb(t_two_stacks *s);
void			ps_rrr(t_two_stacks *s);

#endif
