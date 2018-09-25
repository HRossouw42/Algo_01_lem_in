/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrossouw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 16:34:10 by hrossouw          #+#    #+#             */
/*   Updated: 2018/06/05 12:31:54 by hrossouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int j;
	int len;

	i = 0;
	j = 0;
	len = 0;
	while (little[len] != '\0')
		len++;
	if (len == 0)
		return ((char *)(big));
	while (big[i] != '\0')
	{
		while (big[i + j] == little[j])
		{
			if (j == len - 1)
				return ((char *)(big + i));
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
