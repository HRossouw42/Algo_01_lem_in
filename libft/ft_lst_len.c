/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrossouw <hrossouw@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 16:50:43 by hrossouw          #+#    #+#             */
/*   Updated: 2018/09/17 17:16:13 by hrossouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_lst_len(t_list *begin_list)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = begin_list->head;
	if (tmp)
	{
		while (tmp)
		{
			i++;
			tmp = tmp->next;
		}
	}
	return (i);
}
