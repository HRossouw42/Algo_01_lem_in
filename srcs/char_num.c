/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrossouw <hrossouw@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 11:50:31 by hrossouw          #+#    #+#             */
/*   Updated: 2018/09/26 11:52:03 by hrossouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	has_char(char **line, char c)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = 0;
	str = *line;
	if (str[0] == '#')
		return (0);
	while (str[++i])
	{
		if (str[i] == c)
			j++;
	}
	return (j);
}

int	is_num(char *str)
{
	int		i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (!(str[i] <= '9' && str[i] >= '0'))
			return (0);
	}
	return (1);
}
