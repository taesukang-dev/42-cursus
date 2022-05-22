#include "so_long.h"

void	press_a(t_game_info *game)
{
	int	i;

	i = 0;
	while (i < ft_strlen(game->map))
	{
		if (game->map[i] == 'P')
			break ;
		i++;
	}
	if (game->map[i - 1] == 'C')
		game->point_count += 1;
	if (game->map[i - 1] == 'E' && game->c_count == game->point_count)
		clear_game(game);
	else if (game->map[i - 1] != '1' && game->map[i - 1] != 'E')
	{
		game->map[i] = '0';
		game->map[i - 1] = 'P';
		game->walk_count += 1;
		printf("%d\n", game->walk_count);
		render(game);
	}
}

void	press_s(t_game_info *game)
{
	int	i;

	i = 0;
	while (i < ft_strlen(game->map))
	{
		if (game->map[i] == 'P')
			break ;
		i++;
	}
	if (game->map[i + game->width] == 'C')
		game->point_count += 1;
	if (game->map[i + game->width] == 'E' && game->c_count == game->point_count)
		clear_game(game);
	else if (game->map[i + game->width] != '1' && \
			game->map[i + game->width] != 'E')
	{
		game->map[i] = '0';
		game->map[i + game->width] = 'P';
		game->walk_count += 1;
		printf("%d\n", game->walk_count);
		render(game);
	}
}

void	press_d(t_game_info *game)
{
	int	i;

	i = 0;
	while (i < ft_strlen(game->map))
	{
		if (game->map[i] == 'P')
			break ;
		i++;
	}
	if (game->map[i + 1] == 'C')
		game->point_count += 1;
	if (game->map[i + 1] == 'E' && game->c_count == game->point_count)
		clear_game(game);
	else if (game->map[i + 1] != '1' && game->map[i + 1] != 'E')
	{
		game->map[i] = '0';
		game->map[i + 1] = 'P';
		game->walk_count += 1;
		printf("%d\n", game->walk_count);
		render(game);
	}
}

void	press_w(t_game_info *game)
{
	int	i;

	i = 0;
	while (i < ft_strlen(game->map))
	{
		if (game->map[i] == 'P')
			break ;
		i++;
	}
	if (game->map[i - game->width] == 'C')
		game->point_count += 1;
	if (game->map[i - game->width] == 'E' && \
		game->c_count == game->point_count)
		clear_game(game);
	else if (game->map[i - game->width] != '1' && \
			game->map[i - game->width] != 'E')
	{
		game->map[i] = '0';
		game->map[i - game->width] = 'P';
		game->walk_count += 1;
		printf("%d\n", game->walk_count);
		render(game);
	}
}
