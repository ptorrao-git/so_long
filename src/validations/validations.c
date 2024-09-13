/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorrao- <ptorrao-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:27:54 by ptorrao-          #+#    #+#             */
/*   Updated: 2024/09/13 11:18:49 by ptorrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	make_struct(char *file, t_game *game)
{
	int		fd;

	fd = 0;
	check_extension(file, game);
	fd = open(file, O_RDONLY);
	game->height = get_map_height(fd, game);
	if (game->height == 0)
		invalid_map_size(game);
	fd = open(file, O_RDONLY);
	get_map(game, fd);
	game->width = get_map_width(game);
}

int	get_map_width(t_game *game)
{
	int	i;
	int	temp;
	int	count;

	i = 0;
	temp = 0;
	count = ft_strclen(game->map[i], '\n');
	i++;
	while (game->map[i])
	{
		temp = ft_strclen(game->map[i], '\n');
		if (temp != count)
			invalid_map_size(game);
		i++;
	}
	return (count);
}

int	get_map_height(int fd, t_game *game)
{
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	line = get_next_line(fd);
	if (!line)
		invalid_line(game);
	i++;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	return (i - 1);
}

void	get_map(t_game *game, int fd)
{
	char	*line;
	int		i;

	line = NULL;
	i = -1;
	game->map = malloc(sizeof(char *) * (game->height + 1));
	if (!game->map)
		invalid_malloc(game);
	while (++i < game->height)
		game->map[i] = get_next_line(fd);
	line = get_next_line(fd);
	free(line);
	game->map[i] = NULL;
}

void	check_extension(char *file, t_game *game)
{
	if (ft_strncmp(file + ft_strlen(file) - 4, ".ber", 4) != 0)
		invalid_extension(game);
}
