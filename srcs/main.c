/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrossouw <hrossouw@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 11:51:12 by hrossouw          #+#    #+#             */
/*   Updated: 2018/09/26 11:52:03 by hrossouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	print_list(t_room **room)
{
	t_room	*tmp;
	t_link	*tmp_con;
	tmp = *room;
	while (tmp)
	{
		ft_putstr("\nThis might be room: ");
		ft_putstr(tmp->ident);
		ft_putstr("\nThe start is: ");
		ft_putstr(ft_itoa(tmp->is_start));
		ft_putstr("\nThe end is: ");
		ft_putstr(ft_itoa(tmp->is_end));
		tmp_con = tmp->connect;
		ft_putstr("\n");
		ft_putstr("This is linked to rooms :");
		while (tmp_con)
		{
			ft_putstr(tmp_con->room->ident);
			ft_putstr(", ");
			tmp_con = tmp_con->next;
			if (tmp_con == '\0')
				break ;
		}
		ft_putstr("\n");
		tmp = tmp->next;
	}
}

static void	add_starts(t_room **room)
{
	t_room	*tmp;

	tmp = *room;
	while (tmp)
	{
		tmp->start_connections = tmp->connect;
		tmp = tmp->next;
	}
}
int			main(void)
{
	t_room		*room;
	t_room		*end;
	t_opt		*best;
	t_room		*num;

	num = 
	room = receive();
	print_list(&room);
	calc_routes_needed(&room);
	add_starts(&room);
	init_routes(&room);
	end = find_end(&room);
	no_overlaps(&end->routes);
	best = find_opt(&end->routes);
	ft_putstr("num_routes = ");
	ft_putstr(ft_itoa(best->num_routes));
	ft_putstr("\nlength total = ");
	ft_putstr(ft_itoa(best->len_tot));
	ft_putstr("\n");
	simulation(&room, best);
	return (1);
}
