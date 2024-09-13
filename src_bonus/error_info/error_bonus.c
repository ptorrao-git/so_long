/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorrao- <ptorrao-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:30:15 by ptorrao-          #+#    #+#             */
/*   Updated: 2024/09/12 11:37:45 by ptorrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

void	invalid_open(void)
{
	ft_printf("Error\n");
	ft_printf("Could not open the file or file does not exist!\n");
	exit (EXIT_SUCCESS);
}

void	invalid_arguments(void)
{
	ft_printf("Error\n");
	ft_printf("Invalid arguments\nHow to use: ./so_long maps/(map name)\n");
	exit (EXIT_SUCCESS);
}

void	invalid_extension(t_game *game)
{
	ft_printf("Error\n");
	ft_printf("Invalid map file extension, it should be a \".ber\" file\n");
	ft_exit(game);
}

void	invalid_line(t_game *game)
{
	ft_printf("Error\n");
	ft_printf("Could not read line\n");
	ft_exit(game);
	exit (EXIT_SUCCESS);
}

void	invalid_malloc(t_game *game)
{
	ft_printf("Error\n");
	ft_printf("Invalid malloc\n");
	ft_exit(game);
}
