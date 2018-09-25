/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrossouw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 16:58:27 by hrossouw          #+#    #+#             */
/*   Updated: 2018/06/05 17:39:27 by hrossouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	check;
	size_t	len;
	size_t	i;

	check = ft_min(ft_strlen(big) + 1, n);
	len = ft_strlen(little);
	i = 0;
	if (!(unsigned char)little[0])
		return (char *)(big);
	while (i < check && len <= (n - i))
	{
		if (ft_strncmp((big + i), little, len) == 0)
			return (char *)(big + i);
		i++;
	}
	return (NULL);
}
