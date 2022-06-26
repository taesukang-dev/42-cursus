CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
LIBFT = libft
SRCS = command_r.c \
		command_sp.c \
		doubly_list.c \
		push_swap_utils.c \
		push_swap.c \
		sorted_arr_utils.c \
		sorting_utils.c \
		sorting.c \
		swap_utils.c \
		swap.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIBFT)
	$(CC) -o $(NAME) -L./$(LIBFT) -lft $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJS)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re