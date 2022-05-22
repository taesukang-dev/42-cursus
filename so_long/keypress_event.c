#include "so_long.h"

void	clear_game(t_game_info *game)
{
	game->walk_count += 1;
	printf("end with %d steps!\n", game->walk_count);
	exit(0);
}

int	keypress_event(int key, t_game_info *game)
{
	if (key == ESC)
		click_redcross(game);
	if (key == A)
		press_a(game);
	if (key == S)
		press_s(game);
	if (key == D)
		press_d(game);
	if (key == W)
		press_w(game);
	return (0);
}

int	click_redcross(t_game_info *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit(0);
}
