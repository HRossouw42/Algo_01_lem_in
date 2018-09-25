/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrossouw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 13:14:05 by hrossouw          #+#    #+#             */
/*   Updated: 2018/06/05 12:42:32 by hrossouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*new_str;
	size_t			len;
	unsigned int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	len = ft_strlen(s) - 1;
	while (len > i && (s[len] == ' ' || s[len] == '\n' || s[len] == '\t'))
		len--;
	return (new_str = ft_strsub(s, i, len - (size_t)i + 1));
}
