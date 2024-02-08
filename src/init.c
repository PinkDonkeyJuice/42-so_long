/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyvergni <gyvergni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:51:50 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/02/08 15:49:18 by gyvergni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_position(t_game *game)
{
	int	i;
	int	j;
	int	nb_children;

	i = 0;
	nb_children = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->length)
		{
			if (game->map[i][j] == 'P')
			{
				game->x = i;
				game->y = j;
				break ;
			}
			if (game->map[i][j] == 'C')
				nb_children++;
			j++;
		}
		i++;
	}
	game->nb_children = nb_children;
}

void	init_game(t_game *game, void *mlx_id)
{
	game->x = 0;
	game->y = 0;
	game->height = 0;
	game->length = 0;
	game->nb_moves = 0;
	game->nb_children = 0;
	game->map = NULL;
	game->mlx_id = mlx_id;
	game->mlx_window = NULL;
	game->last_keypress = 0;
	init_sprites(game);
}

void	init_car_sprites(t_game *game)
{
	int	size;

	size = 64;
	game->mlx_car_up = mlx_xpm_file_to_image(game->mlx_id, \
		"./xpm/car_road_up.xpm", &size, &size);
	game->mlx_car_right = mlx_xpm_file_to_image(game->mlx_id, \
		"./xpm/car_road_right.xpm", &size, &size);
	game->mlx_car_left = mlx_xpm_file_to_image(game->mlx_id, \
		"./xpm/car_road_left.xpm", &size, &size);
	game->mlx_car_down = mlx_xpm_file_to_image(game->mlx_id, \
		"./xpm/car_road_down.xpm", &size, &size);
	game->mlx_car_blood_up = mlx_xpm_file_to_image(game->mlx_id, \
		"./xpm/car_bloody_road_up.xpm", &size, &size);
	game->mlx_car_blood_down = mlx_xpm_file_to_image(game->mlx_id, \
		"./xpm/car_bloody_road_down.xpm", &size, &size);
	game->mlx_car_blood_left = mlx_xpm_file_to_image(game->mlx_id, \
		"./xpm/car_bloody_road_left.xpm", &size, &size);
	game->mlx_car_blood_right = mlx_xpm_file_to_image(game->mlx_id, \
		"./xpm/car_bloody_road_right.xpm", &size, &size);
}

void	init_sprites(t_game *game)
{
	int	size;

	size = 64;
	game->mlx_wall = mlx_xpm_file_to_image(game->mlx_id, \
		"./xpm/roof.xpm", &size, &size);
	game->mlx_road = mlx_xpm_file_to_image(game->mlx_id, \
		"./xpm/road.xpm", &size, &size);
	game->mlx_child = mlx_xpm_file_to_image(game->mlx_id, \
		"./xpm/child.xpm", &size, &size);
	game->mlx_exit_open = mlx_xpm_file_to_image(game->mlx_id, \
		"./xpm/garage_open.xpm", &size, &size);
	game->mlx_exit_close = mlx_xpm_file_to_image(game->mlx_id, \
		"./xpm/garage_closed.xpm", &size, &size);
	game->mlx_road_blood = mlx_xpm_file_to_image(game->mlx_id, \
		"./xpm/bloody_road.xpm", &size, &size);
	init_car_sprites(game);
}
