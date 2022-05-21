#include "so_long.h"

int counting_char(char c, t_game_info *game)
{
    if (c == 'E')
        game->e_count += 1;
    if (c == 'P')
        game->p_count += 1;
    if (c == 'C')
        game->c_count += 1;
    return 0;
}

int char_check(char map)
{
    if (map != '1' && map != '0' && map != 'E' && map != 'P' && map != 'C')
        return 0;
    return 1;
}

int wall_check(t_game_info *game)
{
    int     i;

    i = 0;
    while(game->map[i])
    {
        if ((13 - i > 0 || i / 13 >= game->height - 1) && game->map[i] != '1')
            printf("first line or last line\n");
        else
        {
            if (!char_check(game->map[i]))
                printf("invalid char");
            if ((i % game->width == 0 || i % game->width == game->width - 1) && game->map[i] != '1')
                printf("0 or width\n");
        }
        counting_char(game->map[i], game);
        i++;
    }
    return 0;
}