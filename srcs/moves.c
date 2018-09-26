/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrossouw <hrossouw@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 11:51:25 by hrossouw          #+#    #+#             */
/*   Updated: 2018/09/26 11:52:03 by hrossouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void		del_last_item(t_storage *storage)
{
	t_storage	*tmp;

	tmp = storage;
	while (tmp->next && tmp->next->next)
		tmp = tmp->next;
	if (tmp->next)
	{
		free(tmp->next);
		tmp->next = NULL;
	}
}

static void		room_is_end(t_room *room, t_storage *storage)
{
	t_paths	*tmp;

	print_store(storage);
	ft_putstr("\n");
	tmp = room->routes;
	if (room->routes == NULL)
	{
		room->routes = (t_paths *)malloc(sizeof(t_paths));
		room->routes->route = copy_storage(storage);
		room->routes->next = NULL;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = (t_paths *)malloc(sizeof(t_paths));
		tmp->next->route = copy_storage(storage);
		tmp->next->next = NULL;
	}
}

void		ant_move(t_room *room, t_storage *storage)
{
	leave_storage(room, storage);
	add_room_storage(room, &storage);
	if (room->is_end)
	{
		room_is_end(room, storage);
		return ;
	}
	else
	{
		room->connect = room->start_connections;
		while (room->connect)
		{
			if ((!(is_stored(room->connect->room->ident, storage))))
			{
				ant_move(room->connect->room, storage);
				del_last_item(storage);
			}
			room->connect = room->connect->next;
		}
	}
}
