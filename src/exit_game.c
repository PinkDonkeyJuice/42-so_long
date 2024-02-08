/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyvergni <gyvergni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:12:47 by gyvergni          #+#    #+#             */
/*   Updated: 2024/02/08 14:02:50 by gyvergni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_game(t_game *game)
{
	free_map(game->map);
	mlx_destroy_image(game->mlx_id, game->mlx_car_up);
	mlx_destroy_image(game->mlx_id, game->mlx_car_down);
	mlx_destroy_image(game->mlx_id, game->mlx_car_right);
	mlx_destroy_image(game->mlx_id, game->mlx_car_left);
	mlx_destroy_image(game->mlx_id, game->mlx_road);
	mlx_destroy_image(game->mlx_id, game->mlx_wall);
	mlx_destroy_image(game->mlx_id, game->mlx_child);
	mlx_destroy_image(game->mlx_id, game->mlx_exit_open);
	mlx_destroy_image(game->mlx_id, game->mlx_exit_close);
	mlx_destroy_image(game->mlx_id, game->mlx_car_blood_left);
	mlx_destroy_image(game->mlx_id, game->mlx_car_blood_right);
	mlx_destroy_image(game->mlx_id, game->mlx_car_blood_up);
	mlx_destroy_image(game->mlx_id, game->mlx_car_blood_down);
	mlx_destroy_image(game->mlx_id, game->mlx_road_blood);
	if (game == NULL)
		ft_putstr_fd(1, "game null");
}

int	exit_game(t_game *game)
{
	free_game(game);
	if (game->mlx_window != NULL)
		mlx_destroy_window(game->mlx_id, game->mlx_window);
	mlx_destroy_display(game->mlx_id);
	free(game->mlx_id);
	free(game);
	exit(1);
	return (0);
}
