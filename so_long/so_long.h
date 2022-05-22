#ifndef SO_LONG_H
# define SO_LONG_H

#include "./minilibx_opengl_20191021/mlx.h"
#include "get_next_line.h"

#include <fcntl.h>

// perror, strerror
#include <stdio.h>

#define KEY_PRESS   2
#define KEY_EXIT    17

#define ESC         53
#define A           0
#define S           1
#define D           2
#define W           13

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
    int     e_count; // exit
    int     p_count; // start point
    int     c_count; // collection
	int		point_count; // earning collections
	int		walk_count;
    char    *map;
} t_game_info;

void     init_game_info(int fd, t_game_info *game);

int     ft_strlen_without_nl(char *str);
char	*ft_strdup_without_nl(char	*s1);
void	ft_strlcpy_without_nl(char *dest, char *src, int read_len);
char	*ft_strjoin_without_nl(char *s1, char *s2);
int     ft_strlen(char *str);

void     save_info(char *buf, int height, t_game_info *game);
void     wall_check(t_game_info *game);
int     char_check(char map);
void     counting_char(char c, t_game_info *game);

t_img   init_img(void *mlx);
void     render(t_game_info *game);

int     keypress_event(int key, t_game_info *game);
int     click_redcross(t_game_info *game);

void     press_a(t_game_info *game);
void     press_s(t_game_info *game);
void     press_w(t_game_info *game);
void     press_d(t_game_info *game);

void     clear_game(t_game_info *game);

void	print_errors(char *str);

#endif