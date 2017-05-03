#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/24 16:11:32 by apoplavs          #+#    #+#              #
#    Updated: 2017/05/03 13:50:02 by apoplavs         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = lem-in

CC = gcc

LIBFT = libftprintf/libftprintf.a

SRC = main.c get_next_line.c error_management.c\
validation_data.c read_data.c validation_rooms.c\
navigation.c find_way.c move_ants.c

OBJ = $(SRC:.c=.o)

HEADERS = libftprintf/ft_printf.h lem_in.h get_next_line.h

FLAGS = -Wall

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) -o $(NAME) $(OBJ) $(LIBFT)

$(OBJ): %.o: %.c
	$(CC) -c $(FLAGS) $< -o $@

$(LIBFT):
	make -C libftprintf/

libft_clean:
	make -C libftprintf/ clean

libft_fclean:
	make -C libftprintf/ fclean

clean: libft_clean
	rm -f $(OBJ) lem_in.h.gch get_next_line.h.gch *~

fclean: clean libft_fclean
	rm -f $(NAME)

re: fclean all
