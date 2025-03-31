#include "so_long.h"

void	init_game(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->map = NULL;
	game->width = 0;
	game->height = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->collectibles = 0;
	game->collected = 0;
	game->moves = 0;
	game->exit_x = 0;
	game->exit_y = 0;
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
	{
		ft_printf("Error\nUsage: ./so_long map_file.ber\n");
		return (1);
	}
	init_game(&game);
	if (!read_map(&game, av[1]))
	{
		free_map(&game);
		return (1);
	}
	return (0);
}
