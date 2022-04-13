CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = my_printf.a
LIBFT = libft
SRCS = ft_printf.c \
	   printf_di.c \
	   printf_hex.c \
	   printf_u.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIBFT)
	cp libft/libft.a $(NAME)
	ar rcs $@ $?

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
