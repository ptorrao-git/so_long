/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorrao- <ptorrao-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:43:02 by ptorrao-          #+#    #+#             */
/*   Updated: 2024/09/12 15:52:26 by ptorrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

void	count_enemies(t_game *game)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	j = 0;
	c = 0;
	while (game->map[i])
	{
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'R')
				c++;
			j++;
		}
		i++;
		j = 0;
	}
	if (c == 0)
		enemies_error(game);
}

void	check_letters(t_game *game)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	j = 0;
	c = 0;
	while (game->map[i])
	{
		while (game->map[i][j])
		{
			if ((game->map[i][j] == 'R' || game->map[i][j] == 'P'
			|| game->map[i][j] == 'C' || game->map[i][j] == '1'
			|| game->map[i][j] == '0' || game->map[i][j] == 'E'
			|| game->map[i][j] == '\n'))
				j++;
			else
				invalid_map(game);
		}
		i++;
		j = 0;
	}
}
