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
**
*/
t_two_stacks	*ft_create_two_stacks(unsigned int stacksize);

#endif
