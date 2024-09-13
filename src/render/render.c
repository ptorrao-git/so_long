/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorrao- <ptorrao-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:20:34 by ptorrao-          #+#    #+#             */
/*   Updated: 2024/09/12 14:15:37 by ptorrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

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
}

void	draw_tile(t_game *game, int x, int y)
{
	void	*img;

	if (game->map[y][x] == '1')
		img = game->li.w;
	else if (game->map[y][x] == 'P')
		img = game->li.p;
	else if (game->map[y][x] == 'C')
		img = game->li.c;
	else if (game->map[y][x] == 'E')
		img = game->li.e;
	else
		img = game->li.path;
	if (img)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			img, (x * 64), (y * 64));
}

void	render_grid(t_game *game)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	load_images(game);
	while (game->map[++y])
	{
		while (game->map[y][++x])
			draw_tile(game, x, y);
		x = -1;
	}
}

int	key_pressed(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		close_game(game);
	if (keycode == XK_w)
		walk_up(game);
	if (keycode == XK_s)
		walk_down(game);
	if (keycode == XK_d)
		walk_right(game);
	if (keycode == XK_a)
		walk_left(game);
	return (0);
}

void	ft_render(t_game *game)
{
	check_img_files(game);
	game->win_ptr = mlx_new_window(game->mlx_ptr, (game->width * game->tile.x),
			(game->height * game->tile.y), "so_long");
	render_grid(game);
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, key_pressed, game);
	mlx_hook(game->win_ptr, DestroyNotify, NoEventMask, close_game, game);
	mlx_loop(game->mlx_ptr);
}
