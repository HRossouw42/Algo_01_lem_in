/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrossouw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 11:29:15 by hrossouw          #+#    #+#             */
/*   Updated: 2018/06/20 11:30:32 by hrossouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(const char *s1, const char *s2, size_t len)
{
	char	*str;
	int		nbr;
	char	*d;

	nbr = ft_strlen(s1) + ++len;
	str = ft_strnew(nbr);
	d = str;
	while (*s1)
		*str++ = *s1++;
	while (*s2 && --len > 0)
		*str++ = *s2++;
	*str = '\0';
	return (str - (str - d));
}
