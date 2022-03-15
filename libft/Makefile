CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
OBJS = $(SRCS:.c=.o)
SRCS = ft_atoi.c \
ft_bzero.c \
ft_calloc.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_memchr.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memmove.c \
ft_memset.c \
ft_strchr.c \
ft_strdup.c \
ft_strjoin.c \
ft_strlcat.c \
ft_strlcpy.c \
ft_strlen.c \
ft_strncmp.c \
ft_strnstr.c \
ft_strrchr.c \
ft_substr.c \
ft_substr \
ft_tolower.c \
ft_toupper.c \

all: $(NAME)

$(NAME) : $(OBJS)
	ar rc $@ $?

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all