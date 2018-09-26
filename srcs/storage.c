/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrossouw <hrossouw@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 11:51:50 by hrossouw          #+#    #+#             */
/*   Updated: 2018/09/26 11:52:03 by hrossouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int				is_stored(char *ident, t_storage *storage)
{
	t_storage	*tmp;

	tmp = storage;
	while (tmp)
	{
		if (ft_strcmp(tmp->ident, ident) == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void		add_room_storage(t_room *room, t_storage **storage)
{
	t_storage	*tmp;

	tmp = *storage;
	if (!tmp)
	{
		(*storage) = (t_storage *)malloc(sizeof(t_storage));
		(*storage)->next = NULL;
		(*storage)->ident = room->ident;
		if (room->is_start || room->is_end)
		{
			(*storage)->st_end = 1;
		}
		else
			(*storage)->st_end = 0;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = (t_storage *)malloc(sizeof(t_storage));
		tmp->next->next = NULL;
		tmp->next->ident = room->ident;
		if (room->is_start || room->is_end)
			tmp->next->st_end = 1;
		else
			tmp->next->st_end = 0;
	}
}

t_storage	*copy_storage(t_storage *storage)
{
	t_storage	*copy_store;
	t_storage	*start;
	t_storage	*tmp;

	if (storage)
	{
		tmp = storage;
		copy_store = (t_storage *)malloc(sizeof(t_storage));
		copy_store->ident = tmp->ident;
		copy_store->st_end = tmp->st_end;
		start = copy_store;
		while (tmp->next)
		{
			copy_store->next = (t_storage *)malloc(sizeof(t_storage));
			copy_store->next->ident = tmp->next->ident;
			copy_store->next->st_end = tmp->next->st_end;
			copy_store->next->next = NULL;
			tmp = tmp->next;
			copy_store = copy_store->next;
		}
		return (start);
	}
	return (NULL);
}

void		leave_storage(t_room *room, t_storage *storage)
{
	t_storage	*copy_store;

	copy_store = copy_storage(storage);
	room->backpack = copy_store;
}

void		print_store(t_storage *storage)
{
	t_storage *tmp;

	tmp = storage;
	while (tmp)
	{
		ft_putstr(tmp->ident);
		ft_putstr(", ");
		tmp = tmp->next;
	}
	ft_putstr("\n ");
}
