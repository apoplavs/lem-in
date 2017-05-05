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

void		shortcut(t_links *path, int ants)
{
	int		i;

	i = 0;
	while (ants-- > 0)
		ft_printf("L%d-%s ", ++i, path->next->link->name);
	ft_putchar('\n');
}

void		continued_movement(t_links **path, int ants, int *came, int n)
{
	while (path[++n] && path[n]->next
		&& ants < path_len(path[n]) - path_len(path[0]))
		movement(path[n], came);
}

void		on_other_ways(t_links **path, int *ants, int *came, int *i)
{
	int		n;

	n = 0;
	while (path[++n] && path[n]->next
		&& *ants >= path_len(path[n]) - path_len(path[0]) && (*ants)-- > 0)
	{
		(*i)++;
		path[n]->link->occupied = *i;
		movement(path[n], came);
	}
	continued_movement(path, *ants, came, n - 1);
}

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
	int		n;
	int		came;

	came = ants;
	if (path[0]->next->link->status == 2)
		return (shortcut(path[0], ants));
	while (ants-- > 0)
	{
		i++;
		path[0]->link->occupied = i;
		movement(path[0], &came);
		if (path[1] && path[1]->next
			&& ants >= path_len(path[1]) - path_len(path[0]) && ants > 0)
			on_other_ways(path, &ants, &came, &i);
		else
			continued_movement(path, ants, &came, 0);
		ft_putchar('\n');
	}
	while (came)
	{
		n = -1;
		while (path[++n] && path[n]->next)
			movement(path[n], &came);
		ft_putchar('\n');
	}
}
