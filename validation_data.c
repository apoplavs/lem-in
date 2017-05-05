/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 12:15:52 by apoplavs          #+#    #+#             */
/*   Updated: 2017/04/24 12:16:04 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			is_only_digit(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int			check_number_of_ants(char *str)
{
	int		res;

	if (!is_only_digit(str))
		ft_error("ERROR : number of ants is invalid value");
	if (ft_strlen(str) > 10 || (ft_strlen(str) == 10 && str[0] > '2'))
		ft_error("ERROR : I do not hold as many ants");
	res = ft_atoi(str);
	free(str);
	if (res < 1)
		ft_error("ERROR : number of ants should only be positive integer");
	return (res);
}

t_room		*find_element(t_room *room, char *name)
{
	while (room->next_room)
	{
		room = room->next_room;
		if (ft_strequ(room->name, name))
			break ;
	}
	return (room);
}

void		make_link(t_room *room, char *src, char *dst)
{
	t_room	*p;
	t_links	*l;
	t_links	*l1;

	p = find_element(room, dst);
	room = find_element(room, src);
	if (!room->links)
	{
		room->links = malloc(sizeof(t_links));
		room->links->link = p;
		room->links->next = NULL;
	}
	else
	{
		l1 = room->links;
		while (l1->next)
			l1 = l1->next;
		l = malloc(sizeof(t_links));
		l->link = p;
		l->next = NULL;
		l1->next = l;
	}
}

void		print_comments(char *str)
{
	ft_putstr(str);
	ft_putchar('\n');
	free(str);
}
