CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = printf.a
SRCS = ft_printf.c \
	   printf_di.c \
	   printf_hex.c \
	   printf_u.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	ar rcs $@ $?

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
