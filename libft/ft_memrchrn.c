/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrchrn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrossouw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 14:57:35 by hrossouw          #+#    #+#             */
/*   Updated: 2018/06/05 15:04:00 by hrossouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrchrn(const void *s, int c, size_t n)
{
	unsigned char	*buffer;
	size_t			i;

	buffer = (unsigned char *)s;
	i = (n - 1);
	while (i > 0)
	{
		if (buffer[i] == (unsigned char)c)
			return (buffer + i);
		i--;
	}
	if (buffer[0] == (unsigned char)c)
		return ((void *)buffer);
	return (NULL);
}
