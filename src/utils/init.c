/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorrao- <ptorrao-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:57:10 by ptorrao-          #+#    #+#             */
/*   Updated: 2024/09/11 15:41:40 by ptorrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	init_game(t_game *game)
{
	game->map = NULL;
	game->width = 0;
	game->height = 0;
	game->player.x = 0;
	game->player.y = 0;
	game->exit.x = 0;
	game->exit.y = 0;
	game->collectibles = 0;
	game->gathered = 0;
	game->collected = 0;
	game->moves = 0;
	game->coords.x = -1;
	game->coords.y = -1;
	game->tile.x = 0;
	game->tile.y = 0;
}

void	init_img(t_game *game)
{
	game->mlx_ptr = mlx_init();
	game->win_ptr = NULL;
	game->tile.y = SIZE;
	game->tile.x = SIZE;
	game->li.w = NULL;
	game->li.p = NULL;
	game->li.c = NULL;
	game->li.e = NULL;
	game->li.path = NULL;
	game->li.checker = 0;
}

t_game	*init(void)
{
	t_game	*game;

	game = malloc((1) * sizeof(t_game));
	if (!game)
		invalid_malloc(game);
	init_game(game);
	init_img(game);
	return (game);
}
