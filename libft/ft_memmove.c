/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrossouw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 11:23:17 by hrossouw          #+#    #+#             */
/*   Updated: 2018/06/20 15:26:32 by hrossouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*buffer;
	const unsigned char	*source;
	size_t				i;

	buffer = dst;
	source = src;
	i = (len - 1);
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	if (dst == src || !len)
		return (dst);
	while (i > 0)
	{
		buffer[i] = source[i];
		i--;
	}
	buffer[0] = source[0];
	return (dst);
}
