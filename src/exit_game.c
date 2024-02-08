/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pinkdonkeyjuice <pinkdonkeyjuice@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:12:47 by gyvergni          #+#    #+#             */
/*   Updated: 2024/02/08 01:46:16 by pinkdonkeyj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_game(t_game *game)
{
	free_map(game->map);
	free(game->mlx_id);
	free(game->mlx_window);
	free(game->mlx_car_up);
	free(game->mlx_car_down);
	free(game->mlx_car_right);
	free(game->mlx_car_left);
	free(game->mlx_road);
	free(game->mlx_wall);
	free(game->mlx_child);
	free(game->mlx_exit_open);
	free(game->mlx_exit_close);
	free(game->mlx_car_blood_left);
	free(game->mlx_car_blood_right);
	free(game->mlx_car_blood_up);
	free(game->mlx_car_blood_down);
	free(game->mlx_road_blood);
	free(game);
	if (game == NULL)
		ft_putstr_fd(1, "game null");
}

int		exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx_id, game->mlx_window);
	mlx_destroy_display(game->mlx_id);
	free_game(game->mlx_id);
	exit(1);
	return (0);
}