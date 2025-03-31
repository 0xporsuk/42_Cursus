#include "so_long.h"

int	is_rectangular(t_game *game)
{
	int	i;
	int	len;

	if (game->height < 3)
	{
		ft_printf("Error\nMap must have at least 3 rows\n");
		return (0);
	}

	if (game->width < 3)
	{
		ft_printf("Error\nMap must have at least 3 columns\n");
		return (0);
	}

	i = 1;
	while (i < game->height)
	{
		len = ft_strlen(game->map[i]);
		if (len != game->width)
		{
			ft_printf("Error\nMap must be rectangular\n")
			return (0);
		}""
		i++;
	}
	return (1);
}

int is_sur_walls(t_game *game)
{
	int i;

	i = 0;
	while (i < game->width)
	{
		if (game->map[0][i] != WALL || game->map[game->height - 1][i] != WALL)
		{
			ft_printf("Error\nMap must be surrounded by walls\n");
			return (0);
		}
	}

	i = 0;
	while (i < game->height)
	{
		if (game->map[i][0] != WALL || game->map[i][game->height - 1] != WALL)
		{
			ft_printf("Error\nMap must be surrounded by walls\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int req_elements(t_game *game)
{
	int	i;
	int	j;
	int	exit_count;
	int	player_count;
	int	collectible_count;

	exit_count = 0;
	player_count = 0;
	collectible_count = 0;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == EXIT)
				exit_count++;
			else if
		}
	}

}
