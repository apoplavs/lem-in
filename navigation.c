/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   navigation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 11:04:24 by apoplavs          #+#    #+#             */
/*   Updated: 2017/04/28 11:04:43 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"


t_room		*get_room(t_room *start, int status)
{
	while (start)
	{
		if (start->status == status)
			return (start);
		start = start->next_room;
	}
	return (NULL);
}

int 		get_num_of_room(t_room *room)
{
	int 	i;

	i = 0;
	while (room)
	{
		room = room->next_room;
		i++;
	}
	return (i);
}

int		make_path(t_links *path, t_room *link)
{
	t_links	*new_path;

	while (path->next)
		path = path->next;
	new_path = malloc(sizeof(t_links));
	new_path->link = link;
	new_path->next = NULL;
	path->next = new_path;
	return (1);
}

void 		del_path(t_links *path)
{
	if (!path->next)
		return ;
	while (path->next->next)
		path = path->next;
	free(path->next);
	path->next = NULL;
}

int 	path_len(t_links *path)
{
	int i;

	i = 0;
	while (path->next)
	{
		i++;
		path = path->next;
	}
	return (i);
}