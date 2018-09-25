/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_ft_get_next_line.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrossouw <hrossouw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 14:27:04 by hrossouw          #+#    #+#             */
/*   Updated: 2018/08/14 15:59:55 by hrossouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_findfd(t_list **start, int fd)
{
	t_list	*temp;

	temp = *start;
	if (temp)
	{
		while (temp)
		{
			if (fd == (int)temp->content_size)
				return (temp);
			temp = temp->next;
		}
	}
	temp = ft_lstnew("\0", 1);
	temp->content_size = fd;
	ft_lstadd(start, temp);
	return (temp);
}

char			*ft_join_free(char *temp, char *buff, int rb)
{
	char	*str;

	str = temp;
	temp = ft_strnjoin(temp, buff, rb);
	free(str);
	return (temp);
}

int				ft_get_next_line(int const fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	int				rb;
	static t_list	*list;
	t_list			*begin;
	char			*l;

	if (fd < 0 || line == NULL || read(fd, buf, 0) < 0)
		return (-1);
	begin = list ? list : NULL;
	list = ft_findfd(&begin, fd);
	while (!ft_strchr(list->content, '\n') && (rb = read(fd, buf, BUFF_SIZE)))
		list->content = ft_join_free(list->content, buf, rb);
	rb = 0;
	while (((char *)list->content)[rb] && ((char *)list->content)[rb] != '\n')
		++rb;
	*line = ft_strndup(list->content, rb);
	if (((char *)list->content)[rb] == '\n')
		++rb;
	l = list->content;
	list->content = ft_strdup(list->content + rb);
	free(l);
	list = begin;
	if (rb > 0)
		return (1);
	return (0);
}
