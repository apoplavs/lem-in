/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 17:05:43 by apoplavs          #+#    #+#             */
/*   Updated: 2017/04/24 17:06:01 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void 		ft_error(char *str)
{
	ft_printf("%s\n", str);
	exit(1);
}

void		del_tab(char **tab)
{
	int		i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab[i]);
	free(tab);
}

t_room 		*create_room(t_room *room)
{
	t_room	*p;

	while (room->next_room != NULL)
		room = room->next_room;
	p = malloc(sizeof(t_room));
	p->name = NULL;
	p->status = -1;
	p->links = NULL;
	p->next_room = NULL;
	p->occupied = 0;
	room->next_room = p;
	return (p);
}

int 		is_room(char *line)
{
	char **tab;

	tab = ft_strsplit(line, ' ');
	if (tab[0] && tab[1] && tab[2])
	{
		del_tab(tab);
		return (1);
	}
	else
	{
		del_tab(tab);
		return (0);
	}
}

void 		delete_rooms(t_room *room)
{
	if (room->name != NULL)
		free(room->name);
	free(room);
}