/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 12:08:38 by apoplavs          #+#    #+#             */
/*   Updated: 2017/04/24 12:08:42 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "get_next_line.h"

typedef struct 		s_links
{
	struct s_room	*link;
	struct 	s_links	*next;
}					t_links;

typedef struct		s_room
{
	char 			*name;
	t_links			*links;
	int 			status;
	int 			occupied;
	int 			x;
	int 			y;
	struct s_room	*next_room;
}					t_room;

/*
 ** validation_data.c
 */
int 		is_only_digit(char *str);
int 		check_number_of_ants(char *str);
void		make_link(t_room *room, char *src, char *dst);

/*
 ** validation_rooms.c
 */
int 		check_description_room(t_room *start, char **tab);
int			check_coordinates(t_room *start, int x, int y);
int			check_name_room(t_room *start, char *name);
int			check_room_status(int status, t_room *room);
void		ft_set_occupied(t_room *rooms);

/*
 ** error_management.c
 */
void 		ft_error(char *str);
t_room 		*create_room(t_room *room);
void		del_tab(char **tab);
int 		is_room(char *line);
void 		delete_room(t_room *room);

/*
 ** read_data.c
 */
int			read_start(t_room *rooms, char *line);
int			read_end(t_room *rooms, char *line);
int			read_room(t_room *rooms, char *line);
int			read_link(t_room *rooms, char *line);
void		ft_read_links(t_room *rooms, char *line);

/*
 ** find_way.c
 */
t_links		**path_init(t_room *start, int ways);
int 		shortest_route(t_room *start, t_links *path);
int			route(t_room *room, t_links *path, int i, int max);
t_links		**find_way(t_room *start, t_room *room, int ways);

/*
 ** navigation.c
 */
t_room		*get_room(t_room *start, int status);
int 		get_num_of_room(t_room *room);
int			make_path(t_links *path, t_room *link);
void 		del_path(t_links *path);
int 		path_len(t_links *path);


/*
 ** move_ants.c
 */
void		ants_run(int i, t_links **path, int ants);

#endif