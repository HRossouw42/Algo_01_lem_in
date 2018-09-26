/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrossouw <hrossouw@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 11:50:49 by hrossouw          #+#    #+#             */
/*   Updated: 2018/09/26 11:52:03 by hrossouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	add_to_room_end(t_room **start, t_room *new)
{
	t_room *tmp;

	if (*start == NULL)
		*start = new;
	else
	{
		tmp = *start;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->next = NULL;
	}
}

t_room	*find_start(t_room **room)
{
	t_room	*tmp;

	tmp = *room;
	while (tmp)
	{
		if (tmp->is_start)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

t_room	*find_end(t_room **room)
{
	t_room	*tmp;

	tmp = *room;
	while (tmp)
	{
		if (tmp->is_end)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void	sharp(char **line)
{
	while ((*line)[0] == '#' && (*line)[1] != '#')
		gnf(line);
}
