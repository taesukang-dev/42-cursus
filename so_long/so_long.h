#ifndef SO_LONG_H
# define SO_LONG_H

#include "./minilibx_opengl_20191021/mlx.h"
#include "get_next_line.h"
#include "./libft/libft.h"

#include <fcntl.h>

// perror, strerror
#include <stdio.h>

typedef struct s_img
{
    void    *by; // yoda
    void    *cl; // collection
    void    *fl; // floor
    void    *md; // mando
    void    *wl; // wall
} t_img;


typedef struct s_game_info
{
    void    *mlx;
    void    *mlx_win;
    t_img   img;
    int     width;
    int     height;
    int     e_count;
    int     p_count;
    int     c_count;
    char    *map;
} t_game_info;

int     save_info(char *buf, int height, t_game_info *game);
int     init_game_info(int fd, t_game_info *game);

int     ft_strlen_without_nl(char *str);
char	*ft_strdup_without_nl(char	*s1);
void	ft_strlcpy_without_nl(char *dest, char *src, int read_len);
char	*ft_strjoin_without_nl(char *s1, char *s2);

int save_info(char *buf, int height, t_game_info *game);
int wall_check(t_game_info *game);
int char_check(char map);
int counting_char(char c, t_game_info *game);

t_img   init_img(void *mlx);
int render(t_game_info *game);

#endif