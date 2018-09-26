/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrossouw <hrossouw@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 11:51:46 by hrossouw          #+#    #+#             */
/*   Updated: 2018/09/26 11:52:03 by hrossouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	len_store(t_storage *storage)
{
	t_storage	*tmp;
	int			i;

	i = 0;
	tmp = storage;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int		all_taken(t_paths *checking)
{
	t_paths	*tmp;

	tmp = checking;
	while (tmp)
	{
		if (tmp->taken == 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	add_to_list(t_opt_path **start, t_storage *bp, int len)
{
	t_opt_path	*tmp;

	tmp = *start;
	if (tmp->route)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = (t_opt_path *)malloc(sizeof(t_opt_path));
		tmp->next->route = bp;
		tmp->next->route_len = len;
		tmp->next->next = NULL;
	}
	else
	{
		tmp->route = bp;
		tmp->route_len = len;
		tmp->next = NULL;
	}
}

void	define_len_routes(t_opt *best, t_opt_path *sort)
{
	t_paths		*checking;
	int			i;
	int			j;
	t_paths		*smallest;

	i = 0;
	j = 9999999;
	checking = best->routes->checking;
	while (checking)
	{
		checking->taken = 0;
		checking = checking->next;
	}
	checking = best->routes->checking;
	while (checking && !all_taken(checking))
	{
		while (checking)
		{
			i = len_store(checking->route);
			if (i < j && checking->taken == 0)
			{
				if (smallest)
					smallest->taken = 0;
				j = i;
				smallest = checking;
				smallest->taken = 1;
			}
			checking = checking->next;
		}
		checking = best->routes->checking;
		add_to_list(&sort, smallest->route, j);
		smallest = NULL;
		j = 9999999;
	}
}

void	initial(t_opt_path **sort)
{
	(*sort) = (t_opt_path *)malloc(sizeof(t_opt_path));
	(*sort)->next = NULL;
	(*sort)->route = NULL;
	(*sort)->route_len = 0;
}

void	simulation(t_room **rooms, t_opt *best)
{
	t_opt_path		*sort;
	t_ant			*ant;
	t_room			*start;

	start = find_start(rooms);
	sort = NULL;
	initial(&sort);
	define_len_routes(best, sort);
	ant = ant_create(&start);
	move_ant(rooms, sort, ant);
}

