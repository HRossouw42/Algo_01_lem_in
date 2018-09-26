/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_routes_needed.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrossouw <hrossouw@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 11:50:26 by hrossouw          #+#    #+#             */
/*   Updated: 2018/09/26 11:52:03 by hrossouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	len_list(t_link *storage)
{
	t_link		*copy;
	int			i;

	i = 0;
	copy = storage;
	while (copy)
	{
		copy = copy->next;
		i++;
	}
	return (i);
}

void		calc_routes_needed(t_room **room)
{
	t_room	*start;
	t_room	*end;
	int		start_num;
	int		end_num;

	if ((start = find_start(room)))
	{
		if ((end = find_end(room)))
		{
			start_num = len_list(start->connect);
			end_num = len_list(end->connect);
			if (start_num > end_num)
				end->routes_needed = start_num;
			else
				end->routes_needed = end_num;
			return ;
		}
	}
	else
		error();
}
