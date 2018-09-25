/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_prefix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrossouw <hrossouw@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 12:40:57 by hrossouw          #+#    #+#             */
/*   Updated: 2018/09/17 17:13:50 by hrossouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list		*ft_lst_prefix(t_list *lst, int value)
{
	t_node	*node;

	if (lst != NULL)
	{
		node = (t_node *)malloc(sizeof(t_node));
		if (node != NULL)
		{
			node->data = value;
			node->prev = NULL;
			if (lst->head == NULL)
			{
				node->next = NULL;
				lst->head = node;
				lst->tail = node;
			}
			else
			{
				lst->head->prev = node;
				node->next = lst->head;
				lst->head = node;
			}
			lst->len++;
		}
	}
	return (lst);
}
