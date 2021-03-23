#include "instructions_ps.h"

int	check_duplicates(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
			{
				ft_putstr_fd("Error\n", 2);
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
