#include "so_long.h"

int counting_char(char *buf, t_game_info *game)
{
    int     i;

    i = 0;
    while(buf[i])
    {
        if (i == 'e')
            game->e_count += 1;
        if (i == 'p')
            game->p_count += 1;
        if (i == 'c')
            game->c_count += 1;
        i++;
    }
    return 0;
}

int wall_check(char *buf, int height, int width, t_game_info *game)
{
    if (height == 0 || height == game->height)
    {
        while(*buf)
        {
            if (*buf != 1)
                return 0;
            buf++;
        }
    }
    else if (height != 0 && game->height != height)
    {
        // [0], [width - 1] == 1
        // !e, !p, !c, !0, !1 ??
    }

    return 0;
}

int init_game_info(char *buf, int height, t_game_info *game)
{
    int     width;

    width = ft_strlen(buf);
    if (!height)
        game->width = width - 1;
    if (game->width != width - 1)
        return 0;
    wall_check(buf, height, game->width, game); 
    // 맵을 다 저장하고 wall_check를 돌려야되나...?
    // index % 13 == 1 || 0
    // 13 - i > 0 , 첫줄 || index / 13 >= height - 1, 마지막줄
    
    counting_char(buf, game);
    // game -> save map lines...?
    free(buf);
    return 0;
}

int is_valid_map(int fd)
{
    int     height;
    char    *buf;
    char    *last;
    t_game_info *game;
    
    ft_calloc(1, sizeof(t_game_info));
    height = 0;
    buf = get_next_line(fd);
    while(buf)
    {
        last = ft_strdup(buf); // 마지막줄
        buf = get_next_line(fd);
        if (!buf)
            break ;
        init_game_info(buf, height, game);
        free(last);
        height++;
    }
    game->height = height;
    init_game_info(last, height, game);
    return 0;
}

int main(int ac, char *av[])
{
    
    if (ac != 2)
        return 0;
    
    int fd = open(av[1], O_RDONLY);
    is_valid_map(fd);

    return 0;
}