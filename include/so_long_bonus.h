/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorrao- <ptorrao-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:21:41 by ptorrao-          #+#    #+#             */
/*   Updated: 2024/09/13 11:01:59 by ptorrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <X11/keysym.h>
# include <X11/X.h>
# include "../libft/ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include "../libft/get_next_line/get_next_line_bonus.h"
# include "../minilibx-linux/mlx.h"
# include "limits.h"

# define SIZE 64

typedef struct s_coord
{
	int	x;
	int	y;
}				t_point;

typedef struct s_load_img
{
	void	*w;
	void	*p;
	void	*c;
	void	*e;
	void	*pu0;
	void	*pu1;
	void	*pr0;
	void	*pr1;
	void	*pl0;
	void	*pl1;
	void	*pd0;
	void	*pd1;
	void	*grab;
	void	*r;
	void	*path;
	void	*black;
	int		checker;
}			t_load_img;

typedef struct s_game
{
	char		**map;
	int			width;
	int			height;
	int			collectibles;
	int			gathered;
	int			collected;
	int			moves;
	int			bi;
	t_point		coords;
	t_point		player;
	t_point		exit;
	t_point		tile;
	void		*mlx_ptr;
	void		*win_ptr;
	t_load_img	li;
}				t_game;

/* Error Functions */

void	invalid_open(void);
void	invalid_arguments(void);
void	invalid_extension(t_game *game);
void	invalid_line(t_game *game);
void	invalid_malloc(t_game *game);
void	invalid_map_size(t_game *game);
void	collectible_error(t_game *game);
void	enemies_error(t_game *game);
void	player_error(t_game *game);
void	exit_error(t_game *game);
void	walls_error(t_game *game);
void	path_error(t_game *game);
void	missing_img_file(t_game *game);
void	invalid_map(t_game *game);

/* Validations */

void	check_extension(char *file, t_game *game);
void	check_map_content(t_game *game);
void	check_path(t_game *game);
void	check_img_files(t_game *game);
void	check_img_files_2(t_game *game);
void	make_struct(char *file, t_game *game);
void	validate_map(char *path, t_game	*game);
void	ft_render(t_game *game);
void	count_enemies(t_game *game);
void	check_letters(t_game *game);
int		check_up(t_game *game);
int		check_down(t_game *game);
int		check_right(t_game *game);
int		check_left(t_game *game);

/* Building map */

t_game	*init(void);
void	init_img(t_game *game);
void	init_game(t_game *game);
void	get_map(t_game *game, int fd);
int		get_map_width(t_game *game);
int		get_map_height(int fd, t_game *game);
void	load_images(t_game *game);
void	load_images_2(t_game *game);
void	display_counter(t_game *game);
void	put_tile(t_game *game, int x, int y);

/* Key Actions */

int		close_game(t_game *game);
void	walk_up(t_game *game);
void	walk_down(t_game *game);
void	walk_right(t_game *game);
void	walk_left(t_game *game);

/* Freeing actions */

void	free_array(char **map, int lines);
void	free_map(char **map, t_game *game);
void	free_all(t_game *game);
void	free_images(t_game *game);
int		ft_exit(t_game *game);

#endif