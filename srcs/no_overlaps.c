/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_overlaps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrossouw <hrossouw@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 11:51:31 by hrossouw          #+#    #+#             */
/*   Updated: 2018/09/26 11:52:03 by hrossouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static t_storage	*conflict_route(t_storage *r1, t_storage *r2)
{
	t_storage	*start_old;
	t_storage	*start_new;
	t_storage	*route_new;
	t_storage	*route_old;

	route_old = r1;
	route_new = r2;
	start_new = route_new;
	start_old = route_old;
	while (route_old)
	{
		while (route_new)
		{
			if (!route_new->st_end && !route_old->st_end &&
				ft_strcmp(route_new->ident, route_old->ident) == 0)
			{
				return (start_old);
			}
			route_new = route_new->next;
		}
		route_new = start_new;
		route_old = route_old->next;
	}
	return (NULL);
}

static t_paths	*lst_cpy(t_paths **to_copy)
{
	t_paths	*copy;
	t_paths	*copy_start;
	t_paths	*tmp;

	tmp = *to_copy;
	copy = (t_paths *)malloc(sizeof(t_paths));
	copy->route = tmp->route;
	copy->compatable = NULL;
	copy->next = NULL;
	copy->checking = NULL;
	copy_start = copy;
	while (tmp->next)
	{
		copy->next = (t_paths *)malloc(sizeof(t_paths));
		copy->next->route = tmp->next->route;
		copy->next->compatable = NULL;
		copy->next->next = NULL;
		copy->next->checking = NULL;
		tmp = tmp->next;
		copy = copy->next;
	}
	return (copy_start);
}

static void		add_to_route(t_paths **lst, t_paths *new)
{
	t_paths	*tmp;

	tmp = *lst;
	if (*lst)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = (t_paths *)malloc(sizeof(t_paths));
		tmp->next->next = NULL;
		tmp->next->checking = new->checking;
		tmp->next->compatable = new->compatable;
		tmp->next->route = new->route;
	}
	else
	{
		*lst = (t_paths *)malloc(sizeof(t_paths));
		(*lst)->next = NULL;
		(*lst)->checking = new->checking;
		(*lst)->compatable = NULL;
		(*lst)->route = new->route;
	}
}

static t_paths		*conflict(t_paths *check, t_paths **start)
{
	t_paths	*to_check_start;
	t_paths	*to_check;
	t_paths	*tmp;
	t_paths	*copy_check;
	t_paths	*copy_tmp;

	to_check = check->checking;
	to_check_start = to_check;
	tmp = *start;
	while (tmp)
	{
		while (to_check && !conflict_route(to_check->route, tmp->route))
			to_check = to_check->next;
		if (to_check == NULL)
		{
			to_check = to_check_start;
			copy_check = lst_cpy(&to_check);
			copy_tmp = lst_cpy(&tmp);
			add_to_route(&copy_check, tmp);
			copy_tmp->checking = copy_check;
			copy_tmp->compatable = conflict(copy_tmp, start);
			copy_tmp->checking = copy_check;
			add_to_route(&check->compatable, copy_tmp);
		}
		to_check = to_check_start;
		tmp = tmp->next;
	}
	return (check->compatable);
}

void	no_overlaps(t_paths **start)
{
	t_paths	*tmp;

	tmp = *start;
	while (tmp)
	{
		tmp->checking = (t_paths *)malloc(sizeof(t_paths));
		tmp->checking->next = NULL;
		tmp->checking->route = tmp->route;
		tmp->checking->compatable = NULL;
		tmp->checking->checking = NULL;
		tmp->compatable = NULL;
		tmp = tmp->next;
	}
	tmp = *start;
	while (tmp)
	{
		conflict(tmp, start);
		tmp = tmp->next;
	}
}
