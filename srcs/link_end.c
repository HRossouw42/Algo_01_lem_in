/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrossouw <hrossouw@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 11:51:03 by hrossouw          #+#    #+#             */
/*   Updated: 2018/09/26 11:52:03 by hrossouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static t_link	*new_link(t_room *new)
{
	t_link	*new_con;

	new_con = (t_link *)malloc(sizeof(t_link));
	new_con->next = NULL;
	new_con->room = new;
	return (new_con);
}

void	add_link_to_end(t_link **start, t_room *new)
{
	t_link	*tmp;

	if (*start == NULL || (*start)->room == NULL)
	{
		*start = new_link(new);
	}
	else
	{
		tmp = *start;
		while (tmp->next)
		{
			if (ft_strcmp(tmp->room->ident, new->ident) == 0)
				return ;
			tmp = tmp->next;
		}
		if (ft_strcmp(tmp->room->ident, new->ident) == 0)
			return ;
		tmp->next = new_link(new);
	}
}
