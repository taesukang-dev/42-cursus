#ifndef LIBFT_H
# define	LIBFT_H
# include <unistd.h>
# include <stdlib.h>
//# include <string.h>

//delete it later
# include <stdio.h>
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(char const *s);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
void	*ft_memset(void *ptr, int value, size_t num);
void	ft_bzero(void *dest, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t num);
#endif
