/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 12:14:21 by apoplavs          #+#    #+#             */
/*   Updated: 2017/04/24 12:14:36 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			read_start(t_room *rooms, char *line)
{
	char	**tab;

	free(line);
	if (!check_room_status(0, rooms))
		return (0);
	if (get_next_line(0, &line) < 1)
		ft_error("ERROR : description of start room not found");
	tab = ft_strsplit(line, ' ');
	if (!check_description_room(rooms, tab) || ft_strstr(line, "  ")
		|| line[ft_strlen(line) - 1] == ' ' || line[0] == ' ')
		ft_error("ERROR : invalid description of start room");
	ft_putstr("##start\n");
	rooms = create_room(rooms);
	rooms->name = ft_strdup(tab[0]);
	rooms->x = ft_atoi(tab[1]);
	rooms->y = ft_atoi(tab[2]);
	del_tab(tab);
	rooms->status = 0;
	ft_putstr(line);
	ft_putchar('\n');
	free(line);
	return (1);
}

int			read_end(t_room *rooms, char *line)
{
	char	**tab;

	free(line);
	if (!check_room_status(2, rooms))
		return (0);
	if (get_next_line(0, &line) < 1)
		ft_error("ERROR : description of end room not found");
	tab = ft_strsplit(line, ' ');
	if (!check_description_room(rooms, tab) || ft_strstr(line, "  ")
		|| line[ft_strlen(line) - 1] == ' ' || line[0] == ' ')
		ft_error("ERROR : invalid description of end room");
	ft_putstr("##end\n");
	rooms = create_room(rooms);
	rooms->name = ft_strdup(tab[0]);
	rooms->x = ft_atoi(tab[1]);
	rooms->y = ft_atoi(tab[2]);
	del_tab(tab);
	rooms->status = 2;
	ft_putstr(line);
	ft_putchar('\n');
	free(line);
	return (1);
}

int			read_room(t_room *rooms, char *line)
{
	char	**tab;

	tab = ft_strsplit(line, ' ');
	if (!check_description_room(rooms, tab) || ft_strstr(line, "  ")
		|| line[ft_strlen(line) - 1] == ' ' || line[0] == ' ')
	{
		free(line);
		return (0);
	}
	ft_putstr(line);
	ft_putchar('\n');
	rooms = create_room(rooms);
	rooms->name = ft_strdup(tab[0]);
	rooms->x = ft_atoi(tab[1]);
	rooms->y = ft_atoi(tab[2]);
	del_tab(tab);
	rooms->status = 1;
	free(line);
	return (1);
}

int			read_link(t_room *rooms, char *line)
{
	char	**tab;

	if (ft_strlen(line) < 3
		|| !(tab = check_link_name(rooms, rooms, line))
		|| !tab[1] || ft_strequ(tab[0], tab[1]))
		return (0);
	ft_putstr(line);
	ft_putchar('\n');
	make_link(rooms, tab[0], tab[1]);
	make_link(rooms, tab[1], tab[0]);
	del_tab(tab);
	free(line);
	return (1);
}

void		ft_read_links(t_room *rooms, char *line)
{
	if (ft_strchr(line, '-'))
	{
		if (!read_link(rooms, line))
			return ;
	}
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strchr(line, '-'))
		{
			if (!read_link(rooms, line))
				break ;
		}
		else if (line[0] == '#')
			print_comments(line);
		else
			break ;
	}
	free(line);
}
