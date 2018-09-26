/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrossouw <hrossouw@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 11:50:20 by hrossouw          #+#    #+#             */
/*   Updated: 2018/09/26 11:52:03 by hrossouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static char	*make_name(int num)
{
	char	str[2];
	char	*ret;

	str[0] = 'L';
	str[1] = '\0';
	ret = ft_strjoin(str, ft_itoa(num));
	return (ret);

}

static void	init_ant(t_ant **ant, int num, t_room *start)
{
	*ant = (t_ant *)malloc(sizeof(t_ant));
	if (ant == 0)
		error();
	(*ant)->next = NULL;
	(*ant)->name = make_name(num);
	(*ant)->room = start;
	(*ant)->route = NULL;
	(*ant)->moves = 0;
}

t_ant		*ant_create(t_room **rooms)
{
	t_room		*start;
	t_ant		*ant;
	t_ant		*ant_start;
	int			i;

	i = 1;
	if (i == 0)
		error();
	i = 1;
	start = *rooms;
	init_ant(&ant, i, start);
	ant_start = ant;
	i++;
	while (i <= start->num_of_lem)
	{
		init_ant(&ant->next, i, start);
		ant = ant->next;
		i++;
	}
	return (ant_start);
}
