/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorrao- <ptorrao-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:00:07 by ptorrao-          #+#    #+#             */
/*   Updated: 2024/09/13 10:45:32 by ptorrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

void	free_array(char **map, int lines)
{
	int	i;

	i = -1;
	if (!map[0])
	{
		free(map);
		return ;
	}
	while (++i < lines)
		free(map[i]);
	free(map);
}

void	free_map(char **map, t_game *game)
{
	int	i;

	i = -1;
	if (!map[0])
	{
		free (game->map);
		return ;
	}
	while (++i < game->height)
		free(game->map[i]);
	free(game->map);
}

void	free_all(t_game *game)
{
	if (!game)
		return ;
	if (game->map)
		free_map(game->map, game);
	if (game->li.checker == 1)
		free_images(game);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	free(game);
}

void	free_images(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->li.w);
	mlx_destroy_image(game->mlx_ptr, game->li.p);
	mlx_destroy_image(game->mlx_ptr, game->li.c);
	mlx_destroy_image(game->mlx_ptr, game->li.e);
	mlx_destroy_image(game->mlx_ptr, game->li.pu0);
	mlx_destroy_image(game->mlx_ptr, game->li.pu1);
	mlx_destroy_image(game->mlx_ptr, game->li.pd0);
	mlx_destroy_image(game->mlx_ptr, game->li.pd1);
	mlx_destroy_image(game->mlx_ptr, game->li.pr0);
	mlx_destroy_image(game->mlx_ptr, game->li.pr1);
	mlx_destroy_image(game->mlx_ptr, game->li.pl0);
	mlx_destroy_image(game->mlx_ptr, game->li.pl1);
	mlx_destroy_image(game->mlx_ptr, game->li.grab);
	mlx_destroy_image(game->mlx_ptr, game->li.r);
	mlx_destroy_image(game->mlx_ptr, game->li.path);
	mlx_destroy_image(game->mlx_ptr, game->li.black);
}

int	ft_exit(t_game *game)
{
	free_all(game);
	exit (EXIT_SUCCESS);
}
