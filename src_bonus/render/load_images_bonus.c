/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorrao- <ptorrao-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:05:40 by ptorrao-          #+#    #+#             */
/*   Updated: 2024/09/13 10:46:34 by ptorrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

void	load_images(t_game *game)
{
	int	w;
	int	h;

	game->li.w = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/bush.xpm", &w, &h);
	game->li.p = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/p.xpm", &w, &h);
	game->li.c = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/c.xpm", &w, &h);
	game->li.e = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/e.xpm", &w, &h);
	game->li.path = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/path.xpm", &w, &h);
	game->li.pu0 = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/pu0.xpm", &w, &h);
	game->li.pu1 = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/pu1.xpm", &w, &h);
	game->li.black = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/black.xpm", &w, &h);
}

void	load_images_2(t_game *game)
{
	int	w;
	int	h;

	game->li.pr0 = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/pr0.xpm", &w, &h);
	game->li.pr1 = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/pr1.xpm", &w, &h);
	game->li.pl0 = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/pl0.xpm", &w, &h);
	game->li.pl1 = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/pl1.xpm", &w, &h);
	game->li.pd0 = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/pd0.xpm", &w, &h);
	game->li.pd1 = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/pd1.xpm", &w, &h);
	game->li.grab = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/grab.xpm", &w, &h);
	game->li.r = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/r.xpm", &w, &h);
}
