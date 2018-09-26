/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_notes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrossouw <hrossouw@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 11:50:36 by hrossouw          #+#    #+#             */
/*   Updated: 2018/09/26 11:52:03 by hrossouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	error_empty(int num_of_ant)
{
	if (num_of_ant == 0)
		error();
}

void	error(void)
{
	ft_putstr(RED"Error\n");
	exit(1);
}
