/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorrao- <ptorrao-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:55:12 by ptorrao-          #+#    #+#             */
/*   Updated: 2024/09/12 15:22:17 by ptorrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

void	path_error(t_game *game)
{
	ft_printf("Error\n");
	ft_printf("The player can't reach all collectibles or exit\n");
	ft_exit(game);
}

void	missing_img_file(t_game *game)
{
	ft_printf("Error\n");
	ft_printf("One or more image files are missing\n");
	ft_exit(game);
}

void	enemies_error(t_game *game)
{
	ft_printf("Error\n");
	ft_printf("There should be at least 1 Enemy\n");
	ft_exit(game);
}

void	invalid_map(t_game *game)
{
	ft_printf("Error\n");
	ft_printf("This is an Invalid map\n");
	ft_exit(game);
}
