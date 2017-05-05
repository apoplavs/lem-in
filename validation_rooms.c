/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_rooms.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 17:07:22 by apoplavs          #+#    #+#             */
/*   Updated: 2017/04/26 17:07:36 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_description_room(t_room *start, char **tab)
{
	if (!tab[0] || !tab[1] || !tab[2] || tab[3]
		|| tab[0][0] == 'L' || tab[0][0] == '#'
		|| !is_only_digit(tab[1]) || !is_only_digit(tab[2])
		|| !check_name_room(start, tab[0])
		|| (tab[1][0] == '0' && tab[1][1])
		|| (tab[2][0] == '0' && tab[2][1])
		|| !check_coordinates(start, ft_atoi(tab[1]), ft_atoi(tab[2])))
		return (0);
	else
		return (1);
}

int		check_coordinates(t_room *start, int x, int y)
{
	while (start->next_room != NULL)
	{
		start = start->next_room;
		if (start->x == x && start->y == y)
			return (0);
	}
	return (1);
}

int		check_name_room(t_room *start, char *name)
{
	while (start->next_room != NULL)
	{
		start = start->next_room;
		if (ft_strequ(start->name, name))
			return (0);
	}
	return (1);
}

int		check_room_status(int status, t_room *room)
{
	while (room->next_room)
	{
		room = room->next_room;
		if (room->status == status)
			return (0);
	}
	return (1);
}

void	ft_set_occupied(t_room *rooms)
{
	while (rooms)
	{
		rooms->occupied = 0;
		rooms = rooms->next_room;
	}
}
