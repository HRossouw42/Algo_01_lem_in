/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrossouw <hrossouw@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 11:51:41 by hrossouw          #+#    #+#             */
/*   Updated: 2018/09/26 11:52:03 by hrossouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_room		*make_room(char **input, int start_end, int num_of_ant)
{
	t_room	*room;

	room = (t_room *)malloc(sizeof(t_room));
	room->ident = input[0];
	room->posx = input[1];
	room->posy = input[2];
	room->next = NULL;
	room->is_start = 0;
	room->is_end = 0;
	room->num_of_lem = 0;
	room->connect = NULL;
	room->backpack = NULL;
	room->routes = NULL;
	if (start_end == 1)
	{
		room->is_start = 1;
		room->num_of_lem = num_of_ant;
	}
	else if (start_end == 2)
	{
		room->is_end = 1;
	}
	return (room);
}

void		gnf(char **line)
{
	free(*line);
	get_next_line(0, line);
}

t_room		*read_input(char **line, int num_of_ant)
{
	char	**input;
	t_room	*room;
	int		start_end;

	error_empty(num_of_ant);
	start_end = 0;
	sharp(line);
	if (ft_strcmp(*line, "##start") == 0 || ft_strcmp(*line, "##end") == 0)
	{
		if ((*line)[2] == 's')
			start_end = 1;
		else
			start_end = 2;
		gnf(line);
	}
	if (has_char(line, ' ') == 2)
	{
		input = ft_strsplit(*line, ' ');
		if (is_num(input[1]) && is_num(input[2]))
		{
			room = make_room(input, start_end, num_of_ant);
			return (room);
		}
	}
	return (NULL);
}

static void	ret_free(t_room *start, char *line)
{
	int ret;

	ret = link_create(&start, &line);
	free(line);
}

t_room		*receive(void)
{
	t_room	*room;
	t_room	*start;
	char	*line;
	int		num_of_ant;
	int		ret;

	num_of_ant = 0;
	start = NULL;
	while (get_next_line(0, &line) > 0 && (!has_char(&line, '-')))
	{
		if (has_char(&line, ' ') == 0 && num_of_ant == 0 && is_num(line))
			num_of_ant = ft_atoi(line);
		else if ((room = read_input(&line, num_of_ant)))
			add_to_room_end(&start, room);
		else
			return (start);
		free(line);
	}
	ret = link_create(&start, &line);
	free(line);
	while (ret && get_next_line(0, &line) > 0 && ft_strcmp(line, "") != 0)
		ret_free(start, line);
	return (start);
}
