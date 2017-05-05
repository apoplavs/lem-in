/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_links.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 15:22:16 by apoplavs          #+#    #+#             */
/*   Updated: 2017/05/05 15:22:21 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char		**tab_init(void)
{
	char	**tab;

	if (!(tab = (char**)malloc(sizeof(char*) * 3)))
		return (NULL);
	tab[0] = NULL;
	tab[1] = NULL;
	tab[2] = NULL;
	return (tab);
}

void		check_second_room(t_room *room, char *p, char **tab)
{
	while (room->next_room != NULL)
	{
		room = room->next_room;
		if (ft_strequ(room->name, p))
		{
			tab[1] = ft_strdup(p);
			break ;
		}
	}
}

char		**check_link_name(t_room *start, t_room *room, char *line)
{
	char	**tab;
	char	*p;

	tab = tab_init();
	p = NULL;
	while (start->next_room != NULL)
	{
		start = start->next_room;
		if (!ft_strncmp(start->name, line, ft_strlen(start->name))
			&& line[ft_strlen(start->name)] == '-')
		{
			tab[0] = ft_strnew(ft_strlen(start->name));
			ft_strncpy(tab[0], line, ft_strlen(start->name));
			p = &line[ft_strlen(start->name)];
			break ;
		}
	}
	if (!tab[0] || !p || *p != '-')
		return (NULL);
	p++;
	check_second_room(room, p, tab);
	return (tab);
}

t_room		*init_rooms(void)
{
	t_room	*rooms;

	rooms = malloc(sizeof(t_room));
	rooms->next_room = NULL;
	rooms->name = NULL;
	rooms->links = NULL;
	rooms->occupied = -1;
	rooms->status = -1;
	rooms->x = -1;
	rooms->y = -1;
	return (rooms);
}
