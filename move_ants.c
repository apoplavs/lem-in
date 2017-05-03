/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 15:11:29 by apoplavs          #+#    #+#             */
/*   Updated: 2017/04/28 15:11:41 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		movement(t_links *path, int *came)
{
	if (!path->next)
		return ;
	movement(path->next, came);
	if (path->link->occupied)
	{
		path->next->link->occupied = path->link->occupied;
		ft_printf("L%d-%s ", path->link->occupied, path->next->link->name);
		path->link->occupied = 0;
		if (path->next->link->status == 2)
			(*came)--;
	}
}

void		ants_run(int i, t_links **path, int ants)
{
	int 	n;
	int 	came;

	came = ants;
	ft_putchar('\n');
	while (ants-- > 0)
	{
		i++;
		path[0]->link->occupied = i;
		movement(path[0], &came);
		n = 0;
		while (path[++n]->next && ants >= path_len(path[n]) - path_len(path[0]) && ants-- > 0)
		{
			i++;
			path[n]->link->occupied = i;
			movement(path[n], &came);
		}
		ft_putchar('\n');
	}
	while (came)
	{
		n = -1;
		while (path[++n]->next)
			movement(path[n], &came);
		ft_putchar('\n');
	}
}