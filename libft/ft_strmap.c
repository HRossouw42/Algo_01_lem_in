/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrossouw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 18:14:15 by hrossouw          #+#    #+#             */
/*   Updated: 2018/06/06 11:34:56 by hrossouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*new_string;
	unsigned int	i;
	unsigned int	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	new_string = ft_strnew(len);
	if (new_string == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_string[i] = f(s[i]);
		i++;
	}
	return (new_string);
}
