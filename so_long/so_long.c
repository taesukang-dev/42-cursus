#include "so_long.h"

int save_info(char *buf, int height, t_game_info *game)
{
    int     width;

    width = ft_strlen_without_nl(buf);
    if (height == 1)
        game->width = width;
    else if (game->width != width)
        return 0;
    game->height = height;
    game->map = ft_strjoin_without_nl(game->map, buf);
    free(buf);
    return 0;
}

int init_game_info(int fd, t_game_info *game)
{
    char    *buf;
    int     height;

    height = 1;
    buf = get_next_line(fd);
    save_info(buf, height, game);
    while(buf)
    {
        height++;
        buf = get_next_line(fd);
        if (!buf)
            break ;
        save_info(buf, height, game);
    }
    return 0;
}

int main(int ac, char *av[])
{
    int         fd;
    t_game_info *game;
    
    game = calloc(1, sizeof(t_game_info));
    if (ac != 2)
        return 0;
    fd = open(av[1], O_RDONLY);
    init_game_info(fd, game);
    wall_check(game);
    
    return 0;
}