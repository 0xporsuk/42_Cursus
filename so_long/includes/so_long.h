#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
#include <ft_printf.h>
#include <libft.h>
#include <get_next_line.h>

# include <mlx.h>

# define EMPTY '0'
# define WALL '1'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define PLAYER 'P'

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

typedef struct s_game
{
	void *mlx;
	void *win;
	char **map;
	int width;
	int height;
	int player_x;
	int player_y;
	int collectibles;
	int collected;
	int moves;
	int exit_x;
	int exit_y;
}t_game;

void	init_game(t_game *game);



#endif

