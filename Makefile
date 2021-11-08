# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahuber <marvin@42lausanne.ch>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/07 14:35:45 by ahuber            #+#    #+#              #
#    Updated: 2021/11/08 10:59:02 by ahuber           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 			= gcc
CFLAGS		= -Wall -Wextra -Werror -Imlx
OPTIONS 	= -Lmlx -lmlx -lz -framework OpenGL -framework AppKit
NAME		= so_long


FOLDER	= ./srcs/
D_M		= mandatory/

SRCS	= $(D_M)main.c\
		  $(D_M)check_map.c\
		  $(D_M)draw_player.c\
		  $(D_M)get_next_line.c\
		  $(D_M)move_player.c\
		  $(D_M)draw_map.c\
		  $(D_M)ft_itoa.c\
		  $(D_M)load_map.c\
		  $(D_M)move_check.c\
		  $(D_M)put_images.c\
		  $(D_M)utils.c\

SOURCES =  $(addprefix $(FOLDER), $(SRCS))

OBJECTS = $(SOURCES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OPTIONS) -o $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)
	rm -f $(OBJECTS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
