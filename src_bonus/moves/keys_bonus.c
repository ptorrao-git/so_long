/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorrao- <ptorrao-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:10:49 by ptorrao-          #+#    #+#             */
/*   Updated: 2024/09/12 16:29:07 by ptorrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

int	close_game(t_game *game)
{
	game->li.checker = 1;
	ft_exit(game);
	return (0);
}

void	walk_up(t_game *game)
{
	int	i;

	i = 0;
	i = check_up(game);
	if (i == 1)
		return ;
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->li.path,
		(game->player.x * 64), (game->player.y * 64));
	if (game->bi == 0)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->li.pu0,
			((game->player.x) * 64), ((game->player.y - 1) * 64));
	else
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->li.pu1,
			((game->player.x) * 64), ((game->player.y - 1) * 64));
	game->player.y = game->player.y - 1;
	game->moves++;
	display_counter(game);
	if (game->bi == 0)
		game->bi = 1;
	else
		game->bi = 0;
}

void	walk_down(t_game *game)
{
	int	i;

	i = 0;
	i = check_down(game);
	if (i == 1)
		return ;
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->li.path,
		(game->player.x * 64), (game->player.y * 64));
	if (game->bi == 0)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->li.pd0,
			((game->player.x) * 64), ((game->player.y + 1) * 64));
	else
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->li.pd1,
			((game->player.x) * 64), ((game->player.y + 1) * 64));
	game->player.y = game->player.y + 1;
	game->moves++;
	display_counter(game);
	if (game->bi == 0)
		game->bi = 1;
	else
		game->bi = 0;
}

void	walk_right(t_game *game)
{
	int	i;

	i = 0;
	i = check_right(game);
	if (i == 1)
		return ;
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->li.path,
		(game->player.x * 64), (game->player.y * 64));
	if (game->bi == 0)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->li.pr0,
			((game->player.x + 1) * 64), ((game->player.y) * 64));
	else
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->li.pr1,
			((game->player.x + 1) * 64), ((game->player.y) * 64));
	game->player.x = game->player.x + 1;
	game->moves++;
	display_counter(game);
	if (game->bi == 0)
		game->bi = 1;
	else
		game->bi = 0;
}

void	walk_left(t_game *game)
{
	int	i;

	i = 0;
	i = check_left(game);
	if (i == 1)
		return ;
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->li.path,
		(game->player.x * 64), (game->player.y * 64));
	if (game->bi == 0)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->li.pl0,
			((game->player.x - 1) * 64), ((game->player.y) * 64));
	else
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->li.pl1,
			((game->player.x - 1) * 64), ((game->player.y) * 64));
	game->player.x = game->player.x - 1;
	game->moves++;
	display_counter(game);
	if (game->bi == 0)
		game->bi = 1;
	else
		game->bi = 0;
}
