/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrossouw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 15:43:36 by hrossouw          #+#    #+#             */
/*   Updated: 2018/06/05 19:28:10 by hrossouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	int		i;
	int		negative;
	int		output;
	char	*input;

	i = 0;
	negative = 1;
	output = 0;
	input = (char *)s;
	while (*input == ' ' || *input == '\n' || *input == '\t'
			|| *input == '\f' || *input == '\r' || *input == '\v')
		input++;
	if (*input == '-' && ft_isdigit(*(input + 1)))
	{
		negative = -1;
		input++;
	}
	if (*input == '+' && ft_isdigit(*(input + 1)))
		input++;
	while (ft_isdigit(*input))
	{
		output = output * 10 + (*input - '0');
		input++;
	}
	return (output * negative);
}
