/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrossouw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 12:21:16 by hrossouw          #+#    #+#             */
/*   Updated: 2018/06/05 14:17:20 by hrossouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_min(size, ft_strlen((const char *)dst));
	src_len = ft_strlen(src);
	if (dst_len == size)
		return (size + src_len);
	if (src_len < size - dst_len)
		ft_strncat(dst, src, src_len + 1);
	else
	{
		ft_strncat(dst, src, size - dst_len - 1);
		dst[size - 1] = '\0';
	}
	return (dst_len + src_len);
}
