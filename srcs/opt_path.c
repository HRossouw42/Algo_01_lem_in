/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrossouw <hrossouw@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 11:51:36 by hrossouw          #+#    #+#             */
/*   Updated: 2018/09/26 11:52:03 by hrossouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	compare_best(t_opt **best, t_opt **compare)
{
	if ((*best)->routes == NULL)
	{
		(*best)->len_tot = (*compare)->len_tot;
		(*best)->num_routes = (*compare)->num_routes;
		(*best)->routes = (*compare)->routes;
	}
	else
	{
		if ((*best)->num_routes <= (*compare)->num_routes)
		{
			if (!((*best)->num_routes == (*compare)->num_routes) && \
				(*best)->len_tot < (*compare)->len_tot)
			{
				return ;
			}
			else
			{
				(*best)->len_tot = (*compare)->len_tot;
				(*best)->num_routes = (*compare)->num_routes;
				(*best)->routes = (*compare)->routes;
			}
		}
	}
}

static int	count_elem(t_storage *bp)
{
	t_storage	*tmp;
	int			i;

	i = 0;
	tmp = bp;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

static void	save_info(t_paths *lst, t_opt **compare)
{
	t_paths	*tmp;
	t_paths	*tmp_check;

	(*compare)->num_routes = 0;
	(*compare)->len_tot = 0;
	tmp = lst;
	tmp_check = tmp->checking;
	(*compare)->routes = tmp;
	while (tmp_check)
	{
		(*compare)->num_routes++;
		(*compare)->len_tot += count_elem(tmp_check->route);
		tmp_check = tmp_check->next;
	}
}

static t_opt	**find_best(t_paths **lst, t_opt **best, t_opt **compare)
{
	t_paths	*tmp;

	tmp = *lst;
	while (tmp)
	{
		if (tmp->compatable)
			best = find_best(&tmp->compatable, best, compare);
		save_info(tmp, compare);
		compare_best(best, compare);
		tmp = tmp->next;
	}
	return (best);
}

static void	init_best(t_opt **best)
{
	(*best) = (t_opt *)malloc(sizeof(t_opt));
	(*best)->len_tot = 0;
	(*best)->num_routes = 0;
	(*best)->routes = NULL;
}

t_opt		*find_opt(t_paths **start)
{
	t_opt		*best;
	t_opt		*compare;
	t_paths		*tmp;

	tmp = *start;
	best = NULL;
	compare = NULL;
	init_best(&best);
	init_best(&compare);
	find_best(&tmp, &best, &compare);
	tmp = tmp->next;
	return (best);
}
