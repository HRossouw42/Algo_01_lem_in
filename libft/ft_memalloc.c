/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrossouw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 12:11:56 by hrossouw          #+#    #+#             */
/*   Updated: 2018/05/30 16:43:07 by hrossouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*buffer;

	buffer = malloc(size);
	if (buffer)
	{
		ft_bzero(buffer, size);
		return (buffer);
	}
	return (0);
}
