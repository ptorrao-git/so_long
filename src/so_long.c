/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorrao- <ptorrao-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:23:09 by ptorrao-          #+#    #+#             */
/*   Updated: 2024/09/12 11:30:12 by ptorrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;
	int		fd;

	if (argc != 2)
		invalid_arguments();
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		invalid_open();
	game = init();
	if (!game)
		invalid_malloc(game);
	validate_map(argv[1], game);
	ft_render(game);
	ft_exit(game);
	return (0);
}
