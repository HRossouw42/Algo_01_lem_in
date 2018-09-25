/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrossouw <hrossouw@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:46:41 by hrossouw          #+#    #+#             */
/*   Updated: 2018/09/17 17:14:06 by hrossouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

long long	ft_atol(const char *str)
{
	long long	res;
	long		sign;

	res = 0;
	sign = 1;
	if (str)
	{
		while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r'
				|| *str == '\f' || *str == '\v')
			str++;
		if (*str == '-')
		{
			sign = -1;
			str++;
		}
		else if (*str == '+')
			str++;
		while (ft_isdigit(*str))
		{
			res += *str++ - '0';
			if (ft_isdigit(*str))
				res = res * 10;
		}
	}
	return (res * sign);
}
