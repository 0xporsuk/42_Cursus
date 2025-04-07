/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 19:21:22 by mdonmeze          #+#    #+#             */
/*   Updated: 2025/04/07 19:40:05 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <ft_printf.h>
# include <libft.h>
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
	void	*mlx;
	void	*win;
	char	**map;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		collected;
	int		moves;
	int		exit_x;
	int		exit_y;

	void	*wall;
	void	*empty;
	void	*player;
	void	*collectible;
	void	*exit;
}t_game;

typedef struct s_img {
	void	*img;
	int		width;
	int		height;
}	t_img;

void	cleanup_and_exit(t_game *game, int exit_code);
int		handle_close(t_game *game);

int		check_file_extension(char *filename);
int		read_map(t_game *game, char *filename);
void	free_map(t_game *game);

int		is_rectangular(t_game *game);
int		is_sur_walls(t_game *game);
void	check_character(t_game *game, int i, int j, int *counts);
int		is_req_elements(t_game *game);
int		validate_map(t_game *game);

int		init_mlx(t_game *game);
void	cleanup_mlx(t_game *game);

void	*load_image(t_game *game, char *path);
int		load_images(t_game *game);
void	draw_tile(t_game *game, void *img, int x, int y);
void	render_map(t_game *game);
void	cleanup_images(t_game *game);

void	move_player(t_game *game, int new_x, int new_y);
int		is_valid_move(t_game *game, int x, int y);
void	try_move(t_game *game, int x, int y);
int		key_hook(int keycode, t_game *game);

char	*get_next_line(int fd);

char	**duplicate_map(t_game *game);
void	flood_fill(char **map, int x, int y, int *reach_counts);
int		check_valid_path(t_game *game);

#endif
