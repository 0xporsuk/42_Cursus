#include "so_long.h"

int	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_printf("Error\nFailed to initialize MLX\n");
		return (0);
	}

	int win_width = game->width * 32;
	int win_height = game->height * 32;

	game->win = mlx_new_window(game->mlx, win_width, win_height, "so_long");
	if (!game->win)
	{
		ft_printf("Error\nFailed to create window\n");
		return (0);
	}
	ft_printf("Window dimensions: %d x %d\n", win_width, win_height);
	return (1);
}

void	cleanup_mlx(t_game *game)
{
	if (game && game->mlx)
	{
		cleanup_images(game);
		if (game->win)
		{
			mlx_destroy_window(game->mlx, game->win);
			game->win = NULL;
		}
		if (game->mlx)
		{
			mlx_destroy_display(game->mlx);
			free(game->mlx);
			game->mlx = NULL;
		}
	}
}
