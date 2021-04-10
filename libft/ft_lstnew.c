/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 01:41:08 by user42            #+#    #+#             */
/*   Updated: 2021/04/11 01:41:09 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newlink;

	newlink = (t_list*)malloc(sizeof(t_list));
	if (!newlink)
		return (NULL);
	newlink->content = content;
	newlink->next = NULL;
	return (newlink);
}
