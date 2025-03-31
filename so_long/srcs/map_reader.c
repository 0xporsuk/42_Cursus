#include "so_long.h"

int	check_file_extension(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len <= 4)
		return (0);
	if (filename[len - 4] != '.' ||
		filename[len - 3] != 'b' ||
		filename[len - 2] != 'e' ||
		filename[len - 1] != 'r')
		return (0);

	return (1);
}
int	count_lines(char *filename)
{
	int fd;
	int line_count;
	char *line;

	line_count = 0;
	fd = open(filename, O_RDONLY)
	if (fd < 0)
		return (-1);

	while ((line = get_next_line(fd)) != NULL)
	{
		line_count++;
		free(line);
	}

	close(fd);
	return (line_count);
}

int	read_map(t_game *game, char *filename)
{
	int		fd;
	int		i;
	char	*line;

	if (!check_file_extension(filename))
	{
		ft_printf("Error\nInvalid file extension. Must be .ber\n");
		return (0);
	}

	game->height = count_lines(filename);
	if (game->height <= 0)
	{
		ft_printf("Error\nFailed to read map or empty file\n");
		return (0);
	}
	game->map = (char **)malloc(sizeof(char *) * (game->height + 1));
	if (!game->map)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		free(game->map)
		game->map = NULL;
		return (0);
	}
	i = 0;
	while (i < game->height)
	{
		line = get_next_line(fd);
		if (!line)
			break;

		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';

		game->map[i] = line;
		i++;
	}
	game->map[i] = NULL;
	close(fd);

	if (game->height > 0)
		game->width = ft_strlen(game->map[0]);

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
