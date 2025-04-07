/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 19:22:19 by mdonmeze          #+#    #+#             */
/*   Updated: 2025/04/07 19:22:20 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	cleanup_and_exit(t_game *game, int exit_code)
{
	free_map(game);
	cleanup_mlx(game);
	exit(exit_code);
}

int	handle_close(t_game *game)
{
	ft_printf("Game closed\n");
	cleanup_and_exit(game, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2 || check_file_extension(av[0]))
	{
		ft_printf("Error\nUsage: ./so_long map_file.ber\n");
		return (1);
	}
	ft_memset(&game, 0, sizeof(t_game));
	if (read_map(&game, av[1]) == 0)
		cleanup_and_exit(&game, 1);
	if (validate_map(&game) == 0)
		cleanup_and_exit(&game, 1);
	if (init_mlx(&game) == 0)
		cleanup_and_exit(&game, 1);
	if (load_images(&game) == 0)
	{
		ft_printf("Error\nFailed to load images\n");
		cleanup_and_exit(&game, 1);
	}
	render_map(&game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_hook(game.win, 17, 0, handle_close, &game);
	mlx_loop(game.mlx);
	return (0);
}
