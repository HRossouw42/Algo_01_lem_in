/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_amount_of_num.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrossouw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 15:36:38 by hrossouw          #+#    #+#             */
/*   Updated: 2018/06/04 15:38:14 by hrossouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_amount_of_num(int num)
{
	int num_amount;

	num_amount = 0;
	if (num == -2147483648)
		return (10);
	if (num == 0)
		return (1);
	if (num < 0)
	{
		num = -num;
		num_amount++;
	}
	while (num)
	{
		num = num / 10;
		num_amount++;
	}
	return (num_amount);
}
