/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorrao- <ptorrao-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:48:51 by ptorrao-          #+#    #+#             */
/*   Updated: 2024/09/12 15:57:09 by ptorrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	validate_map(char *path, t_game	*game)
{
	make_struct(path, game);
	check_map_content(game);
}

void	flood_fill(char **map, t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->width || y >= game->height)
		return ;
	if (map[y][x] == 'F' || map[y][x] == '1')
		return ;
	if (map[y][x] == 'C')
	{
		map[y][x] = 'F';
		game->gathered++;
	}
	if (map[y][x] == 'E' && game->gathered != game->collectibles)
	{
		map[y][x] = 'F';
		return ;
	}
	else
		map[y][x] = 'F';
	flood_fill(map, game, x + 1, y);
	flood_fill(map, game, x, y + 1);
	flood_fill(map, game, x - 1, y);
	flood_fill(map, game, x, y - 1);
}

void	check_path(t_game *game)
{
	char	**map;

	map = malloc(sizeof(char *) * (game->height + 1));
	if (!map)
		invalid_malloc(game);
	game->coords.y = -1;
	while (++game->coords.y < game->height)
		map[game->coords.y] = ft_strdup(game->map[game->coords.y]);
	map[game->coords.y] = NULL;
	flood_fill(map, game, game->player.x, game->player.y);
	game->coords.y = -1;
	while (++game->coords.y < game->height)
	{
		game->coords.x = -1;
		while (++game->coords.x < game->width)
		{
			if (map[game->coords.y][game->coords.x] == 'C'
				|| map[game->coords.y][game->coords.x] == 'E')
			{
				free_array(map, game->height);
				path_error(game);
			}
		}
	}
	free_array(map, game->height);
}

void	check_img_files(t_game *game)
{
	int	fd;

	fd = 0;
	fd = open("textures/bush.xpm", O_RDONLY);
	if (fd < 0)
		missing_img_file(game);
	fd = open("textures/p.xpm", O_RDONLY);
	if (fd < 0)
		missing_img_file(game);
	fd = open("textures/c.xpm", O_RDONLY);
	if (fd < 0)
		missing_img_file(game);
	fd = open("textures/e.xpm", O_RDONLY);
	if (fd < 0)
		missing_img_file(game);
	fd = open("textures/path.xpm", O_RDONLY);
	if (fd < 0)
		missing_img_file(game);
}

void	check_letters(t_game *game)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	j = 0;
	c = 0;
	while (game->map[i])
	{
		while (game->map[i][j])
		{
			if ((game->map[i][j] == 'P' || game->map[i][j] == 'C'
			|| game->map[i][j] == '1' || game->map[i][j] == '0'
			|| game->map[i][j] == 'E' || game->map[i][j] == '\n'))
				j++;
			else
				invalid_map(game);
		}
		i++;
		j = 0;
	}
}
