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

void	cleanup_and_exit(t_game *game, int exit_code)
{
	free_map(game);
	cleanup_mlx(game);
	exit(exit_code);
}
int handle_close(t_game *game)
{
	ft_printf("Game closed\n");
	cleanup_and_exit(game, 0);
	return (0);
}

int main(int ac, char **av)
{
	(void)av;
    t_game game;
    void *img;
    int width, height;

    if (ac != 2)
    {
        ft_printf("Error\nUsage: ./so_long map_file.ber\n");
        return (1);
    }

    // Temel başlatma
    init_game(&game);

    // MLX'i doğrudan başlatın
    game.mlx = mlx_init();
    if (!game.mlx)
    {
        ft_printf("Error\nFailed to initialize MLX\n");
        return (1);
    }

    // Sabit boyutta bir pencere oluşturun
    game.win = mlx_new_window(game.mlx, 640, 480, "Test Window");
    if (!game.win)
    {
        ft_printf("Error\nFailed to create window\n");
        free(game.mlx);
        return (1);
    }

    // Test amaçlı bir XPM dosyası yükleyin (duvar.xpm)
    img = mlx_xpm_file_to_image(game.mlx, "assets/wall.xpm", &width, &height);
    if (img)
    {
        ft_printf("XPM loaded successfully: %dx%d\n", width, height);
        // Görüntüyü (0,0) konumundan başlayarak yayınlayın
        mlx_put_image_to_window(game.mlx, game.win, img, 0, 0);
    }
    else
    {
        ft_printf("Failed to load XPM file\n");
    }

    // Kapatma olayını dinleyin
    mlx_hook(game.win, 17, 0, handle_close, &game);

    // MLX olay döngüsünü başlatın
    mlx_loop(game.mlx);

    return (0);
}
