/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_argv_to_int_array.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 01:34:09 by user42            #+#    #+#             */
/*   Updated: 2021/04/11 01:37:19 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions_ps.h"

int	*convert_argv_to_int_array(int array_size, char *args[])
{
	int			*array;
	char		*endptr;
	long long	tmp;
	int			i;

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
		array[i - 1] = (int)tmp;
		i++;
	}
	return (array);
}
