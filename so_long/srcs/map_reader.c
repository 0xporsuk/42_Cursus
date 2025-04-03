#include "so_long.h"

int	check_file_extension(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len <= 4)
		return (0);
	return (ft_strncmp(&filename[len - 4], ".ber", 4) == 0);
}
int	read_map(t_game *game, char *filename)
{
	int		fd;
	char	*line;
	char	*tmp;

	fd = open(filename, O_RDONLY, 0644);
	if (fd < 0)
		return (0);
	line = NULL;
	tmp = get_next_line(fd);
	if (!tmp)
		cleanup_and_exit(game, 1);
	while (tmp)
	{
		line = ft_strjoin(line, tmp);
		game->height++;
		free(tmp);
		tmp = get_next_line(fd);
	}
	game->map = ft_split(line, '\n');
	game->width = (int)ft_strlen(game->map[0]);
	free(line);
	return (1);
}

void	free_map(t_game *game)
{
	int i;

	if (!game->map)
		return;
	i = 0;
	while (i < game->height)
	{
		if (game->map[i])
			free(game->map[i]);
		i++;
	}
	free(game->map);
	game->map = NULL;
}
