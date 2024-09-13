/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_validations_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorrao- <ptorrao-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:55:18 by ptorrao-          #+#    #+#             */
/*   Updated: 2024/09/12 16:13:20 by ptorrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

int	check_up(t_game *game)
{
	if (game->map[game->player.y - 1][game->player.x] == '1')
		return (1);
	if (game->map[game->player.y - 1][game->player.x] == 'E' &&
		game->collected != game->collectibles)
		return (1);
	if (game->map[game->player.y - 1][game->player.x] == 'E' &&
		game->collected == game->collectibles)
	{
		game->moves++;
		display_counter(game);
		close_game(game);
	}
	if (game->map[game->player.y - 1][game->player.x] == 'R')
	{
		game->moves++;
		display_counter(game);
		close_game(game);
	}
	if (game->map[game->player.y - 1][game->player.x] == 'C')
	{
		game->map[game->player.y - 1][game->player.x] = '0';
		game->collected++;
	}
	return (0);
}

int	check_down(t_game *game)
{
	if (game->map[game->player.y + 1][game->player.x] == '1')
		return (1);
	if (game->map[game->player.y + 1][game->player.x] == 'E' &&
		game->collected != game->collectibles)
		return (1);
	if (game->map[game->player.y + 1][game->player.x] == 'E' &&
		game->collected == game->collectibles)
	{
		game->moves++;
		display_counter(game);
		close_game(game);
	}
	if (game->map[game->player.y + 1][game->player.x] == 'R')
	{
		game->moves++;
		display_counter(game);
		close_game(game);
	}
	if (game->map[game->player.y + 1][game->player.x] == 'C')
	{
		game->map[game->player.y + 1][game->player.x] = '0';
		game->collected++;
	}
	return (0);
}

int	check_right(t_game *game)
{
	if (game->map[game->player.y][game->player.x + 1] == '1')
		return (1);
	if (game->map[game->player.y][game->player.x + 1] == 'E' &&
		game->collected != game->collectibles)
		return (1);
	if (game->map[game->player.y][game->player.x + 1] == 'E' &&
		game->collected == game->collectibles)
	{
		game->moves++;
		display_counter(game);
		close_game(game);
	}
	if (game->map[game->player.y][game->player.x + 1] == 'R')
	{
		game->moves++;
		display_counter(game);
		close_game(game);
	}
	if (game->map[game->player.y][game->player.x + 1] == 'C')
	{
		game->map[game->player.y][game->player.x + 1] = '0';
		game->collected++;
	}
	return (0);
}

int	check_left(t_game *game)
{
	if (game->map[game->player.y][game->player.x - 1] == '1')
		return (1);
	if (game->map[game->player.y][game->player.x - 1] == 'E' &&
		game->collected != game->collectibles)
		return (1);
	if (game->map[game->player.y][game->player.x - 1] == 'E' &&
		game->collected == game->collectibles)
	{
		game->moves++;
		display_counter(game);
		close_game(game);
	}
	if (game->map[game->player.y][game->player.x - 1] == 'R')
	{
		game->moves++;
		display_counter(game);
		close_game(game);
	}
	if (game->map[game->player.y][game->player.x - 1] == 'C')
	{
		game->map[game->player.y][game->player.x - 1] = '0';
		game->collected++;
	}
	return (0);
}
