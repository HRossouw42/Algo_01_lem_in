/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrossouw <hrossouw@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 11:50:53 by hrossouw          #+#    #+#             */
/*   Updated: 2018/09/26 11:52:03 by hrossouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	draw_from_start(t_room **start)
{
	t_room		*room;
	t_storage	*storage;

	storage = NULL;
	room = *start;
	ant_move(room, storage);
}

void	init_routes(t_room **room)
{
	t_room	*start;

	if ((start = find_start(room)))
	{
		draw_from_start(&start);
	}
	else
		ft_putstr(RED"Error\n");
}
