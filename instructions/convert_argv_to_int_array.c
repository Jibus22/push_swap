#include "instructions_ps.h"

int	*convert_argv_to_int_array(int array_size, char *args[])
{
	int		*array;
	char	*endptr;
	long long	tmp;
	int		i;

	array = (int *)malloc(sizeof(*array) * array_size);
	if (!array)
		return (NULL);
	i = 1;
	errno = 0;
	while (args[i])
	{
		tmp = ft_strtoimax(args[i], &endptr);
		if (*endptr || errno == ERANGE)
		{
			ft_putstr_fd("Error\n", 2);
			free(array);
			return (NULL);
		}
		array[i - 1] = (int) tmp;
		i++;
	}
	return (array);
}
