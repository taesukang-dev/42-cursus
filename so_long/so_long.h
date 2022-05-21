#ifndef SO_LONG_H
# define SO_LONG_H

#include "./minilibx_opengl_20191021/mlx.h"
#include "get_next_line.h"
#include "./libft/libft.h"

#include <fcntl.h>

// perror, strerror
#include <stdio.h>

typedef struct s_game_info
{
    int     width;
    int     height;

    int     e_count; // exit > 1
    int     p_count; // start point == 1
    int     c_count; // collections > 0
    char    *map;
} t_game_info;

#endif