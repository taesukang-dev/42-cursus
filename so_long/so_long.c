#include "so_long.h"

int counting_char(char *buf, int height, t_game_info *game)
{
    int     i;

    i = 0;
    while(buf[i])
    {
        if (buf[i] == 'E')
            game->e_count += 1;
        else if (buf[i] == 'P')
            game->p_count += 1;
        else if (buf[i] == 'C')
            game->c_count += 1;
        i++;
    }
    if (height && height == game->height)
    {
        if (game->e_count < 1 || game->p_count != 1 || game->c_count < 1)
            printf("counting_char error\n");
    }
    return 1;
}

int wall_check(char *buf, int height, int width, t_game_info *game)
{
    int     i;

    i = 0;
    if (height == 0 || height == game->height)
    {
        while(buf[i])
        {
            if (buf[i] != '1')
                printf("wall check error\n");
            i++;
        }
    }
    else if (height != 0 && game->height != height)
    {
        if (buf[i] != 1 && buf[width - 1] != 1)
            return 0;
        while (buf[i])
        {
            if (buf[i] != '0' && buf[i] != '1' && buf[i] != 'E' && buf[i] != 'P' && buf[i] != 'C')
                printf("another wall check error\n");
            i++;
        }
    }
    return 0;
}

// 맵을 다 저장하고 wall_check를 돌려야되나...?
// index % 13 == 1 || 0
// 13 - index > 0 , 첫줄 || index / 13 >= height - 1, 마지막줄

int init_game_info(char *buf, int height, t_game_info *game)
{
    int     width;

    // 마지막 줄이면 뉴라인 없어서 하나 적다...
    width = ft_strlen(buf);
    printf("buf : %s\n",buf);
    if (!height)
        game->width = width - 1;
    if (game->width != width - 1)
        return 0;
    counting_char(buf, height, game);
    wall_check(buf, height, game->width, game);
    free(buf);
    return 0;
}

int is_valid_map(int fd)
{
    int     height;
    char    *buf;
    char    *last;
    t_game_info *game;
    
    game = ft_calloc(1, sizeof(t_game_info));
    height = 0;
    buf = get_next_line(fd);
    init_game_info(buf, height, game);
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