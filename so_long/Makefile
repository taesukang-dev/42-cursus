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
	gcc -o $(NAME) $(OBJS) -L./ -lmlx -framework OpenGL -framework Appkit

%.o : %.c
	$(CC) $(CFLAGS) -c $< -I./ -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re