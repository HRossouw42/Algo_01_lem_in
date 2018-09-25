/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrossouw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 11:17:46 by hrossouw          #+#    #+#             */
/*   Updated: 2018/06/05 18:14:20 by hrossouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (ft_min(ft_strlen(s1), ft_strlen(s2)) < n)
		n = ft_min(ft_strlen(s1), ft_strlen(s2)) + 1;
	if (n == 0)
		return (0);
	return (ft_memcmp(s1, s2, n));
}
