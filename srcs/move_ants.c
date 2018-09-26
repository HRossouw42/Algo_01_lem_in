/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrossouw <hrossouw@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 11:51:20 by hrossouw          #+#    #+#             */
/*   Updated: 2018/09/26 11:52:03 by hrossouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static char		*get_r_name(t_storage *route, int moves)
{
	t_storage	*tmp;

	tmp = route;
	while (tmp && moves)
	{
		moves--;
		tmp = tmp->next;
	}
	return (tmp->ident);
}

static t_room	*find_room(char *name, t_room **rooms)
{
	t_room	*tmp;

	tmp = *rooms;
	while (tmp)
	{
		if (ft_strcmp(tmp->ident, name) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

static void		mv_start(t_ant *first, t_opt_path *opt, t_room **rooms)
{
	t_ant		*lem;
	t_opt_path	*routes;
	t_room		*tmp_room;

	routes = opt;
	lem = first;
	while (lem && routes)
	{
		if (lem->moves == 0)
		{
			lem->route = routes->route;
			tmp_room = find_room(get_r_name(lem->route, lem->moves + 1), rooms);
			lem->room = tmp_room;
			tmp_room->num_of_lem++;
			ft_putstr(lem->name);
			ft_putstr("-");
			ft_putstr(tmp_room->ident);
			ft_putstr(" ");
			tmp_room = find_room(get_r_name(lem->route, lem->moves), rooms);
			tmp_room->num_of_lem--;
			lem->moves++;
			routes = routes->next;
		}
		lem = lem->next;
	}
}

static void		mv_play(t_ant *first, t_opt_path *opt, t_room **rooms)
{
	t_ant		*lem;
	t_room		*tmp_room;

	(void)opt;
	lem = first;
	while (lem)
	{
		if (lem->moves && !lem->room->is_end)
		{
			tmp_room = find_room(get_r_name(lem->route, lem->moves + 1), rooms);
			lem->room = tmp_room;
			tmp_room->num_of_lem++;
			ft_putstr(lem->name);
			ft_putstr("-");
			ft_putstr(tmp_room->ident);
			ft_putstr(" ");
			tmp_room = find_room(get_r_name(lem->route, lem->moves), rooms);
			tmp_room->num_of_lem--;
			lem->moves++;
		}
		lem = lem->next;
	}
}

void		move_ant(t_room **rooms, t_opt_path *opt, t_ant *ant)
{
	int				tot_ant;
	t_room			*end;
	t_room			*start;
	t_ant			*first;
	t_opt_path		*best_start;

	best_start = opt;
	end = find_end(rooms);
	start = find_start(rooms);
	first = ant;
	tot_ant = start->num_of_lem;
	mv_start(first, opt, rooms);
	ft_putstr("\n");
	while (end->num_of_lem < tot_ant)
	{
		mv_play(first, opt, rooms);
		mv_start(first, opt, rooms);
		ft_putstr("\n");
	}
}
