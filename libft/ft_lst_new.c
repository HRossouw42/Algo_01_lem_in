/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrossouw <hrossouw@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 16:20:08 by hrossouw          #+#    #+#             */
/*   Updated: 2018/09/17 17:15:14 by hrossouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list		*ft_lst_new(void)
{
	t_list	*result;

	result = (t_list *)malloc(sizeof(t_list));
	if (result != NULL)
	{
		result->len = 0;
		result->head = NULL;
		result->tail = NULL;
	}
	return (result);
}
