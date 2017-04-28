/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 12:06:04 by apoplavs          #+#    #+#             */
/*   Updated: 2017/04/24 12:06:48 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_read_data(t_room *rooms, char *line)
{
	while (get_next_line(0, &line) > 0)
	{
		if (line[0] == '\0')
			ft_error("ERROR : empty line");
		if (ft_strequ(line, "##start"))
		{
			if (!read_start(rooms, line))
				break ;
		}
		else if (ft_strequ(line, "##end"))
		{
			if (!read_end(rooms, line))
				break ;
		}
		else if (line[0] == '#')
			ft_printf("%s\n", line);
		else if (is_room(line))
		{
			if (!read_room(rooms, line))
				break ;
		}
		else
			break ;
	}
	ft_read_links(rooms, line);
}

int 		main(void)
{
	t_room	*rooms;
	t_links	**path;
	int 	ants;
	char 	*line;

	rooms = malloc(sizeof(t_room));
	rooms->next_room = NULL;
	rooms->x = -1;
	rooms->y = -1;
	if (get_next_line(0, &line) < 1 || line[0] == '\0')
		ft_error("ERROR : first line is empty");
	ants = check_number_of_ants(line);
	ft_printf("%d\n", ants);
	ft_read_data(rooms, line);
	if (check_room_status(0, rooms) || check_room_status(2, rooms))
		ft_error("ERROR : no start or end room");
	path = find_way(rooms->next_room, rooms->next_room, ants < 10 ? ants : 10);
	//ants_run(path, ants);
	//ft_del_data(rooms);
	return (0);
}