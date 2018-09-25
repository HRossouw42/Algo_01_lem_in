/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrossouw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 12:39:12 by hrossouw          #+#    #+#             */
/*   Updated: 2018/06/02 15:57:30 by hrossouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	src_len;
	char	*str;

	src_len = ft_strlen(src) + 1;
	str = (char *)ft_memcpy(dst, src, src_len);
	return (str);
}
