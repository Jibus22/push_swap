/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 01:39:53 by user42            #+#    #+#             */
/*   Updated: 2021/04/11 01:39:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Convert string to long long.
** The string may begin with an arbitrary amount of white space
** (as determined by ft_isspace) followed by a single optional `+' or `-' sign.
*/

long long	ft_strtoll(const char *str, char **endptr)
{
	unsigned long long	nbr;
	char				neg;
	short int			i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	neg = 0;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			neg = 1;
	nbr = 0;
	while (ft_isdigit(str[i]))
		nbr = nbr * 10 + str[i++] - 48;
	*endptr = (char *)(&str[i]);
	if ((neg && nbr - 1 > LLONG_MAX) || (!neg && nbr > LLONG_MAX))
	{
		errno = ERANGE;
		return (0);
	}
	if (neg)
		return ((long long)(-nbr));
	else
		return ((long long)nbr);
}
