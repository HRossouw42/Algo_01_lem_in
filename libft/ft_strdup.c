/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrossouw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 14:20:24 by hrossouw          #+#    #+#             */
/*   Updated: 2018/06/02 15:50:26 by hrossouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup_s;
	size_t	len;

	len = ft_strlen(s);
	dup_s = (char *)ft_memalloc(sizeof(char) * (len + 1));
	if (dup_s == NULL)
		return (NULL);
	dup_s = (char *)ft_memcpy(dup_s, s, len);
	return (dup_s);
}
