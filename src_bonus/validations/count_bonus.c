/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorrao- <ptorrao-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:17:11 by ptorrao-          #+#    #+#             */
/*   Updated: 2024/09/12 15:51:17 by ptorrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

void	count_players(t_game *game)
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
			if (game->map[i][j] == 'P')
			{
				c++;
				game->player.x = j;
				game->player.y = i;
			}
			j++;
		}
		i++;
		j = 0;
	}
	if (c != 1)
		player_error(game);
}

void	count_exit(t_game *game)
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
			if (game->map[i][j] == 'E')
				c++;
			j++;
		}
		i++;
		j = 0;
	}
	if (c != 1)
		exit_error(game);
}

void	count_collectibles(t_game *game)
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
			if (game->map[i][j] == 'C')
				c++;
			j++;
		}
		i++;
		j = 0;
	}
	if (c == 0)
		collectible_error(game);
	game->collectibles = c;
}

void	check_walls(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	while (j != game->width)
	{
		if (game->map[0][j] != '1')
			walls_error(game);
		j++;
	}
	while (game->map[i])
	{
		if ((game->map[i][0] != '1') || (game->map[i][game->width - 1] != '1'))
			walls_error(game);
		i++;
	}
	j = 0;
	while (j != game->width)
	{
		if (game->map[game->height - 1][j] != '1')
			walls_error(game);
		j++;
	}
}

void	check_map_content(t_game *game)
{
	count_players(game);
	count_exit(game);
	count_collectibles(game);
	count_enemies(game);
	check_walls(game);
	check_path(game);
	check_letters(game);
}
