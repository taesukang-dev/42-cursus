# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkang <tkang@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/26 12:35:09 by tkang             #+#    #+#              #
#    Updated: 2022/05/26 12:35:16 by tkang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
SRCS = so_long.c \
		get_next_line.c \
		get_next_line_utils.c \
		key_mapping.c \
		keypress_event.c \
		print_errors.c \
		render.c \
		save_info_utils.c \
		validate_map.c \

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) -o $(NAME) $(OBJS) -L./ -lmlx -framework OpenGL -framework Appkit

%.o : %.c
	$(CC) $(CFLAGS) -c $< -I./ -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
