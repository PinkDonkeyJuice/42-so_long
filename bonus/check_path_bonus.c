/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyvergni <gyvergni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:52:04 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/02/09 14:17:23 by gyvergni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	flood(char **map, int row, int col)
{
	if (map[row][col] == '1')
		return ;
	map[row][col] = '1';
	flood(map, row - 1, col);
	flood(map, row + 1, col);
	flood(map, row, col - 1);
	flood(map, row, col + 1);
}

void	check_path(char **map, t_game *game)
{
	flood(map, game->x, game->y);
	if (ft_strchr(map, 'C') || ft_strchr(map, 'E'))
	{
		free_map(map);
		error(game, "No valid path exists\n");
	}
}
