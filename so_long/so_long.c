#include "so_long.h"

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
	close(fd);
	wall_check(game);
	return 0;
}

int init_game(t_game_info *game)
{
	game->mlx = mlx_init();
	game->img = init_img(game->mlx);
	game->mlx_win = mlx_new_window(game->mlx, game->width * 64, game->height * 64, "so_long");
	render(game);
	return 0;
}

int	presskey_event(int key, t_game_info *game)
{
	if (key == 53)
		printf("%d", key);
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
	init_game(game);
	mlx_hook(game->mlx_win, 2, 0, &presskey_event, game);
	// 2번째 인자가 keypress event, 3번째가 keypressmask
	mlx_loop(game->mlx);
	return 0;
}