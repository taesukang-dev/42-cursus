#include "so_long.h"

t_img	init_img(void *mlx)
{
	int		width;
	int		height;
	t_img	img;

	img.by = mlx_xpm_file_to_image(mlx, "./static/by.xpm", &width, &height);
	img.cl = mlx_xpm_file_to_image(mlx, "./static/cl.xpm", &width, &height);
	img.fl = mlx_xpm_file_to_image(mlx, "./static/fl.xpm", &width, &height);
	img.md = mlx_xpm_file_to_image(mlx, "./static/md.xpm", &width, &height);
	img.wl = mlx_xpm_file_to_image(mlx, "./static/wl.xpm", &width, &height);
	return (img);
}

void	render_img(t_game_info *g, int h, int w)
{
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.fl, w * 64, h * 64);
	if (g->map[h * g->width + w] == '1')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.wl, w * 64, h * 64);
	else if (g->map[h * g->width + w] == 'C')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.cl, w * 64, h * 64);
	else if (g->map[h * g->width + w] == 'P')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.md, w * 64, h * 64);
	else if (g->map[h * g->width + w] == 'E')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.by, w * 64, h * 64);
}

void	render(t_game_info *game)
{
	int	height;
	int	width;

	height = 0;
	while (height < game->height)
	{
		width = 0;
		while (width < game->width)
		{
			render_img(game, height, width);
			width++;
		}
		height++;
	}
}
