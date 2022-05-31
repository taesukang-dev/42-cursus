CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = pipex
LIBFT = libft
SRCS = pipex.c \
		pipex_utils.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIBFT)
	# cp libft/libft.a $(NAME)
	# ar rcs $@ $?
	$(CC) -o $(NAME) -L$(LIBFT) -lft $(OBJS)

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