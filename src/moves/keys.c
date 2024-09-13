/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorrao- <ptorrao-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:10:49 by ptorrao-          #+#    #+#             */
/*   Updated: 2024/09/12 11:23:30 by ptorrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	close_game(t_game *game)
{
	game->li.checker = 1;
	ft_exit(game);
	return (0);
}

void	walk_up(t_game *game)
{
	if (game->map[game->player.y - 1][game->player.x] == '1')
		return ;
	if (game->map[game->player.y - 1][game->player.x] == 'E' &&
		game->collected != game->collectibles)
		return ;
	if (game->map[game->player.y - 1][game->player.x] == 'E' &&
		game->collected == game->collectibles)
	{
		ft_printf("%d\n", ++game->moves);
		close_game(game);
	}
	if (game->map[game->player.y - 1][game->player.x] == 'C')
	{
		game->map[game->player.y - 1][game->player.x] = '0';
		game->collected++;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->li.path,
		(game->player.x * 64), (game->player.y * 64));
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->li.p,
		((game->player.x) * 64), ((game->player.y - 1) * 64));
	game->player.y = game->player.y - 1;
	ft_printf("%d\n", ++game->moves);
}

void	walk_down(t_game *game)
{
	if (game->map[game->player.y + 1][game->player.x] == '1')
		return ;
	if (game->map[game->player.y + 1][game->player.x] == 'E' &&
		game->collected != game->collectibles)
		return ;
	if (game->map[game->player.y + 1][game->player.x] == 'E' &&
		game->collected == game->collectibles)
	{
		ft_printf("%d\n", ++game->moves);
		close_game(game);
	}
	if (game->map[game->player.y + 1][game->player.x] == 'C')
	{
		game->map[game->player.y + 1][game->player.x] = '0';
		game->collected++;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->li.path,
		(game->player.x * 64), (game->player.y * 64));
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->li.p,
		((game->player.x) * 64), ((game->player.y + 1) * 64));
	game->player.y = game->player.y + 1;
	ft_printf("%d\n", ++game->moves);
}

void	walk_right(t_game *game)
{
	if (game->map[game->player.y][game->player.x + 1] == '1')
		return ;
	if (game->map[game->player.y][game->player.x + 1] == 'E' &&
		game->collected != game->collectibles)
		return ;
	if (game->map[game->player.y][game->player.x + 1] == 'E' &&
		game->collected == game->collectibles)
	{
		ft_printf("%d\n", ++game->moves);
		close_game(game);
	}
	if (game->map[game->player.y][game->player.x + 1] == 'C')
	{
		game->map[game->player.y][game->player.x + 1] = '0';
		game->collected++;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->li.path,
		(game->player.x * 64), (game->player.y * 64));
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->li.p,
		((game->player.x + 1) * 64), ((game->player.y) * 64));
	game->player.x = game->player.x + 1;
	ft_printf("%d\n", ++game->moves);
}

void	walk_left(t_game *game)
{
	if (game->map[game->player.y][game->player.x - 1] == '1')
		return ;
	if (game->map[game->player.y][game->player.x - 1] == 'E' &&
		game->collected != game->collectibles)
		return ;
	if (game->map[game->player.y][game->player.x - 1] == 'E' &&
		game->collected == game->collectibles)
	{
		ft_printf("%d\n", ++game->moves);
		close_game(game);
	}
	if (game->map[game->player.y][game->player.x - 1] == 'C')
	{
		game->map[game->player.y][game->player.x - 1] = '0';
		game->collected++;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->li.path,
		(game->player.x * 64), (game->player.y * 64));
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->li.p,
		((game->player.x - 1) * 64), ((game->player.y) * 64));
	game->player.x = game->player.x - 1;
	ft_printf("%d\n", ++game->moves);
}
