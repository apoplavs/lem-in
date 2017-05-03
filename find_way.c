/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_way.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 09:28:47 by apoplavs          #+#    #+#             */
/*   Updated: 2017/04/28 09:29:06 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int 		shortest_route(t_room *start, t_links *path)
{
	t_links	*l;

	l = start->links;
	while (l)
	{
		if (l->link->status == 2)
		{
			make_path(path, l->link);
			ft_printf("\n");
			while (path)
			{
				ft_printf("%s", path->link->name);
				if (path->next)
					ft_printf("---");
				path = path->next;
			}
			return (1);
		}
		l = l->next;
	}
	return (0);
}

int			route(t_room *room, t_links *path, int i, int max)
{
	t_links	*l;

	l = room->links;
	room->occupied = 1;
	if (room->status == 2)
	{
		ft_printf("\n");
		while (path)
		{
			ft_printf("%s", path->link->name);
			if (path->next)
				ft_printf("---");
			path = path->next;
		}
		return (1);
	}
	if (i > max)
	{
		del_path(path);
		room->occupied = 0;
		return (0);
	}
	while (l)
	{
		if (l->link->occupied == 0 || l->link->status == 2)
		{
			if (make_path(path, l->link) && route(l->link, path, i + 1, max))
				return (1);
			else
				l->link->occupied = 0;
		}
		l = l->next;
	}
	del_path(path);
	return (0);
}

t_links		**find_way(t_room *start, t_room *room, int ways)
{
	t_links	**path;
	int 	i;
	int 	l;

	//start = get_room(start, 0);
	i = 0;
	l = 0;
	path = path_init(start, ways);
	if (shortest_route(start, path[i]))
		return (path);
	while (l < get_num_of_room(room))
	{
		//ft_printf("i = %d ", l);
		if (route(start, path[i], 0, l))
			i++;
		else
			l++;
	}
	return (path);
}

t_links		**path_init(t_room *start, int ways)
{
	t_links **path;

	path = (t_links**)malloc(sizeof(t_links*) * ways + 1);

	while (ways >= 0)
	{
		path[ways] = malloc(sizeof(t_links));
		path[ways]->link = start;
		path[ways]->next = NULL;
		ways--;
	}
	return (path);
}