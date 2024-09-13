/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorrao- <ptorrao-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:12:16 by ptorrao-          #+#    #+#             */
/*   Updated: 2024/09/12 11:37:51 by ptorrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

void	invalid_map_size(t_game *game)
{
	ft_printf("Error\n");
	ft_printf("Invalid map size\n");
	ft_exit(game);
}

void	collectible_error(t_game *game)
{
	ft_printf("Error\n");
	ft_printf("There should be at least 1 Collectible\n");
	ft_exit(game);
}

void	player_error(t_game *game)
{
	ft_printf("Error\n");
	ft_printf("There should be 1 Player\n");
	ft_exit(game);
}

void	exit_error(t_game *game)
{
	ft_printf("Error\n");
	ft_printf("There should be 1 Exit\n");
	ft_exit(game);
}

void	walls_error(t_game *game)
{
	ft_printf("Error\n");
	ft_printf("The map should be surrounded by walls\n");
	ft_exit(game);
}
