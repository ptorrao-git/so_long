/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorrao- <ptorrao-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:20:34 by ptorrao-          #+#    #+#             */
/*   Updated: 2024/09/13 11:29:33 by ptorrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

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
	else if (game->map[y][x] == 'R')
		img = game->li.r;
	else if (game->map[y][x] == '0')
		img = game->li.path;
	else
		img = game->li.black;
	if (img)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			img, (x * 64), (y * 64));
}

void	put_tile(t_game *game, int x, int y)
{
	int	w;
	int	h;

	if (game->li.black)
		mlx_destroy_image(game->mlx_ptr, game->li.black);
	game->li.black = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/black.xpm", &w, &h);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->li.black, x, y);
}

void	render_grid(t_game *game)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	load_images(game);
	load_images_2(game);
	while (++y < game->height)
	{
		while (game->map[y][++x])
			draw_tile(game, x, y);
		x = -1;
	}
	display_counter(game);
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
	int	fd;

	fd = 0;
	check_img_files(game);
	check_img_files_2(game);
	fd = open("textures/black.xpm", O_RDONLY);
	if (fd < 0)
		missing_img_file(game);
	fd = open("textures/r.xpm", O_RDONLY);
	if (fd < 0)
		missing_img_file(game);
	game->win_ptr = mlx_new_window(game->mlx_ptr, (game->width * game->tile.x),
			((game->height + 1) * game->tile.y), "so_long_bonus");
	render_grid(game);
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, key_pressed, game);
	mlx_hook(game->win_ptr, DestroyNotify, NoEventMask, close_game, game);
	mlx_loop(game->mlx_ptr);
}
