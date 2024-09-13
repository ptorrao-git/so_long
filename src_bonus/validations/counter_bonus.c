/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorrao- <ptorrao-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:04:06 by ptorrao-          #+#    #+#             */
/*   Updated: 2024/09/13 11:02:29 by ptorrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

void	display_counter(t_game *game)
{
	char	*moves;
	int		x;
	int		y;

	x = (game->width - 1) * SIZE;
	y = (game->height + 1) * SIZE;
	moves = ft_itoa(game->moves);
	put_tile(game, x, y - 64);
	mlx_string_put(game->mlx_ptr, game->win_ptr, x, y, 0xCC0000, "MOVES:");
	mlx_string_put(game->mlx_ptr, game->win_ptr, x + 42, y, 0xCC0000, moves);
	free(moves);
}
