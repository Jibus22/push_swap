#include "instructions_ps.h"

int	*convert_argv_to_int_array(int array_size, char *args[])
{
	int	*array;
	int	tmp;
	int	i;

	array = (int *)malloc(sizeof(*array) * array_size);
	if (!array)
		return (NULL);
	i = 1;
	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		array[i - 1] = tmp;
		i++;
	}
	return (array);
}
