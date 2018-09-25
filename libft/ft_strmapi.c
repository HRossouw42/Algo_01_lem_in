/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrossouw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 10:16:14 by hrossouw          #+#    #+#             */
/*   Updated: 2018/06/05 12:00:58 by hrossouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_string;
	unsigned int	i;
	unsigned int	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	new_string = ft_strdup(s);
	if (new_string == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_string[i] = f(i, s[i]);
		i++;
	}
	return (new_string);
}
