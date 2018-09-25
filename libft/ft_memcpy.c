/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrossouw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 08:45:58 by hrossouw          #+#    #+#             */
/*   Updated: 2018/06/02 15:34:43 by hrossouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
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
		i++;
	}
	return (dst);
}
