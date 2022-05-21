#include "so_long.h"

int	keypress_event(int key, t_game_info *game)
{
    if (key == ESC)
        click_redcross(game);
	if (key == A)
	if (key == S)
	if (key == D)
	if (key == W)
		
	return 0;
}

int click_redcross(t_game_info *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit(0);
}