/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrossouw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 14:56:03 by hrossouw          #+#    #+#             */
/*   Updated: 2018/08/13 14:56:40 by hrossouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmove(char *dest, char **src)
{
	char	*tmp;

	if (!src || !dest)
		return (NULL);
	tmp = *src;
	*src = dest;
	ft_freezero((void *)tmp, ft_strlen(tmp));
	return (dest);
}
