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
    if (height == 0)
    {
        while(*buf)
            if (*buf != 1)
                return 0;
    }
    else if (height != 0 && game->height != height)
    else if (height == game->height)

    return 0;
}

int init_game_info(char *buf, int height, t_game_info *game)
{
    int width;

    if (height != 0)
    {
        wall_check(); 
        // last one, start point is width * (height - 1)
    }
    else if (height == game->height)
    {
        width = ft_strlen(buf);
        game->width = width;

    }
}

int is_valid_map(int fd)
{
    int     width;
    int     height;
    char *buf;
    t_game_info *game = ft_calloc(1, sizeof(t_game_info));

    // replace to init_game_info
    buf = get_next_line(fd); // 얘 저장해둬야 되나...?
    width = ft_strlen(buf); 
    game->width = width;
    
    height = 0;
    while(buf)
    {
        buf = get_next_line(fd); 
        width = ft_strlen(buf);
        if (game->width != width)
            return 0;
        counting_char(buf, game);
        // wall_check(buf, height);    
        free(buf);
        height++;
    }
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