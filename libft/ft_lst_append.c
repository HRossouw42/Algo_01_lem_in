/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_append.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrossouw <hrossouw@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 12:25:35 by hrossouw          #+#    #+#             */
/*   Updated: 2018/09/17 15:03:24 by hrossouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list		*ft_lst_append(t_list *lst, int data)
{
	t_node	*node;

	if (lst != NULL)
	{
		node = (t_node *)malloc(sizeof(t_node));
		if (node != NULL)
		{
			node->data = data;
			node->next = NULL;
			if (lst->tail == NULL)
			{
				node->prev = NULL;
				lst->head = node;
				lst->tail = node;
			}
			else
			{
				node->prev = lst->tail;
				lst->tail->next = node;
				lst->tail = node;
			}
			lst->len++;
		}
	}
	return (lst);
}
