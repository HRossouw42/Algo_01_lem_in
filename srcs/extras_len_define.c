/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras_len_define.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrossouw <hrossouw@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 11:50:43 by hrossouw          #+#    #+#             */
/*   Updated: 2018/09/26 11:52:03 by hrossouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	check_move(t_paths *checking, t_paths *smallest, int i, int j)
{
	if (smallest)
		smallest->taken = 0;
	j = i;
	smallest = checking;
	smallest->taken = 1;
}
