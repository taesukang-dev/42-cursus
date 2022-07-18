CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = philo
LIBFT = libft
SRCS = philo.c \
		philo_utils.c \
		routine.c \
		status.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re