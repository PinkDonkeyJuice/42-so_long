/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyvergni <gyvergni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:53:39 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/02/08 16:21:33 by gyvergni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_player(t_game *game, int x, int y)
{
	if (game->map[x][y] == 'P')
	{
		if (game->last_keypress == XK_w || game->last_keypress == XK_Up)
			render_sprite(game, game->mlx_car_up, x, y);
		else if (game->last_keypress == XK_a || game->last_keypress == XK_Left)
			render_sprite(game, game->mlx_car_left, x, y);
		else if (game->last_keypress == XK_d || game->last_keypress == XK_Right)
			render_sprite(game, game->mlx_car_right, x, y);
		else
			render_sprite(game, game->mlx_car_down, x, y);
	}
	else
	{
		if (game->last_keypress == XK_w || game->last_keypress == XK_Up)
			render_sprite(game, game->mlx_car_blood_up, x, y);
		else if (game->last_keypress == XK_a || game->last_keypress == XK_Left)
			render_sprite(game, game->mlx_car_blood_left, x, y);
		else if (game->last_keypress == XK_d || game->last_keypress == XK_Right)
			render_sprite(game, game->mlx_car_blood_right, x, y);
		else
			render_sprite(game, game->mlx_car_blood_down, x, y);
	}
}

void	identify_sprite(t_game *game, int x, int y)
{
	char	element;

	element = game->map[x][y];
	if (element == WALL)
		render_sprite(game, game->mlx_wall, x, y);
	else if (element == GROUND)
		render_sprite(game, game->mlx_road, x, y);
	else if (element == BLOOD)
		render_sprite(game, game->mlx_road_blood, x, y);
	else if (element == CHILD)
		render_sprite(game, game->mlx_child, x, y);
	else if (element == PLAYER || element == CAR_BLOOD)
		render_player(game, x, y);
	else if (element == EXIT)
	{
		if (game->nb_children == 0)
			render_sprite(game, game->mlx_exit_open, x, y);
		else
			render_sprite(game, game->mlx_exit_close, x, y);
	}
}

void	render_sprite(t_game *game, void *mlx_img, int x, int y)
{
	mlx_put_image_to_window(game->mlx_id, game->mlx_window, \
	mlx_img, y * 64, x * 64);
}

void	display_moves(t_game *game)
{
	char	*number;
	char	*display;
	char	*display2;

	number = ft_itoa(game->nb_moves);
	display = ft_strjoin("You made ", number);
	display2 = ft_strjoin(display, " moves");
	mlx_string_put(game->mlx_id, game->mlx_window, 40, 20, 00000, display2);
	free(number);
	free(display);
	free(display2);
	number = ft_itoa(game->nb_children);
	display = "You killed all the children!";
	if (game->nb_children == 0)
		mlx_string_put(game->mlx_id, game->mlx_window, 40, 40, 00001, display);
	else
	{
		display = ft_strjoin("There are ", number);
		display2 = ft_strjoin(display, " children left to run over\n");
		mlx_string_put(game->mlx_id, game->mlx_window, 40, 40, 00001, display2);
		free(display);
		free(display2);
	}
	free(number);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->height)
	{
		y = 0;
		while (y < game->length)
		{
			identify_sprite(game, x, y);
			y++;
		}
		x++;
	}
	display_moves(game);
}
