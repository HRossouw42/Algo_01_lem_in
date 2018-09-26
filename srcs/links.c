/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrossouw <hrossouw@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 11:51:07 by hrossouw          #+#    #+#             */
/*   Updated: 2018/09/26 11:52:03 by hrossouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	tab_len(char **arr)
{
	int		len;

	len = 0;
	while (arr[len] != '\0')
		len++;
	return (len);
}

static char	**get_tube(char **line)
{
	char	**tube;

	tube = NULL;
	if ((*line)[0] == '#' && (*line)[1] != '#')
	{
		free(*line);
		if (get_next_line(0, line) < 1 && (!has_char(line, '-')))
			return (NULL);
	}
	tube = ft_strsplit(*line, '-');
	if (tab_len(tube) != 2 || ft_strcmp(tube[0], tube[1]) == 0)
	{
		while (*tube != '\0')
			free2(tube++);
		tube = NULL;
	}
	return (tube);
}

int		link_create(t_room **room, char **line)
{
	char	**tub;
	t_room	*tmp;
	t_room	*tmp2;

	tmp = *room;
	tmp2 = *room;
	if ((tub = get_tube(line)))
	{
		while (ft_strcmp(tub[0], tmp->ident) != 0)
		{
			if ((tmp = tmp->next) == NULL)
				return (0);
		}
		while (ft_strcmp(tub[1], tmp2->ident) != 0)
		{
			if ((tmp2 = tmp2->next) == NULL)
				return (0);
		}
		add_link_to_end(&tmp->connect, tmp2);
		add_link_to_end(&tmp2->connect, tmp);
		return (1);
	}
	return (0);
}
