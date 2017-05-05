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

int			ft_read_ants(char *line)
{
	int		ants;

	ants = -1;
	while (get_next_line(0, &line) > 0)
	{
		if (line[0] == '\0')
			ft_error("ERROR : empty line");
		else if (ft_strequ(line, "##start") || ft_strequ(line, "##end"))
			ft_error("ERROR : no number of ants");
		else if (line[0] == '#')
			print_comments(line);
		else
		{
			ants = check_number_of_ants(line);
			break ;
		}
	}
	if (ants == -1)
		ft_error("ERROR : invalid file");
	ft_putstr(line);
	ft_putchar('\n');
	return (ants);
}

void		ft_del_data(t_room *room, t_room *rooms, t_links **path)
{
	int		i;

	i = -1;
	while (rooms)
	{
		room = rooms;
		rooms = rooms->next_room;
		delete_room(room);
	}
	while (path[++i])
	{
		while (path[i]->next)
		{
			del_path(path[i]);
		}
		free(path[i]);
	}
	free(path);
}

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
			print_comments(line);
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

int			main(void)
{
	t_room	*rooms;
	t_links	**path;
	int		ants;
	char	*line;

	line = NULL;
	rooms = init_rooms();
	ants = ft_read_ants(line);
	ft_read_data(rooms, line);
	if (check_room_status(0, rooms) || check_room_status(2, rooms))
		ft_error("ERROR : no start or end room");
	path = find_way(get_room(rooms->next_room, 0),
					rooms->next_room, ants < 100 ? ants : 100);
	ft_set_occupied(rooms->next_room);
	if (!path[0]->next)
		ft_error("ERROR : any path not found");
	ft_putchar('\n');
	ants_run(0, path, ants);
	ft_del_data(rooms, rooms, path);
	return (0);
}
