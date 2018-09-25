/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrossouw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 09:49:04 by hrossouw          #+#    #+#             */
/*   Updated: 2018/06/02 15:36:15 by hrossouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*buffer;
	const unsigned char	*source;
	size_t				i;

	buffer = dst;
	source = src;
	i = 0;
	while (i < n)
	{
		buffer[i] = source[i];
		if (source[i] == (unsigned char)c)
			return ((void *)buffer + i + 1);
		i++;
	}
	return (NULL);
}
