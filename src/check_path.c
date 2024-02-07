/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pinkdonkeyjuice <pinkdonkeyjuice@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:52:04 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/02/02 15:34:33 by pinkdonkeyj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void flood(char **map, int row, int col, int length, int height) 
{
	if (map[row][col] == '1') 
        return ;
	map[row][col] = '1';
    flood(map, row - 1, col, length, height);
	flood(map, row + 1, col, length, height);
    flood(map, row, col - 1, length, height);
    flood(map, row, col + 1, length, height);
}

void	check_path(char **map, t_game *game)
{
	flood(map, game->x, game->y, game->length, game->height);
	if (ft_strchr(map, 'C') || ft_strchr(map, 'E'))
		error("No valid path exists\n");
}