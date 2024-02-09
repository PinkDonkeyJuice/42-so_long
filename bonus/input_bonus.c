/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyvergni <gyvergni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:59:27 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/02/09 14:17:47 by gyvergni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	handle_target(t_game *game, int x_dest, int y_dest)
{
	char	*element;

	element = &(game->map[x_dest][y_dest]);
	if (*element != '1' && *element != 'P' && *element != 'p'\
		&& (*element != 'E' || game->nb_children == 0))
	{
		if (*element == 'C')
		{
			*element = 'p';
			game->nb_children--;
		}
		if (*element == 'B')
			*element = 'p';
		if (*element == '0')
			*element = 'P';
		else if (*element == 'E')
			exit_game(game);
		if (game->map[game->x][game->y] == 'P')
			game->map[game->x][game->y] = '0';
		else if (game->map[game->x][game->y] == 'p')
			game->map[game->x][game->y] = 'B';
		game->x = x_dest;
		game->y = y_dest;
		game->nb_moves++;
	}
}

int	handle_keypress(int keycode, t_game *game)
{
	int	x_dest;
	int	y_dest;

	x_dest = game->x;
	y_dest = game->y;
	game->last_keypress = keycode;
	if (keycode == XK_Escape)
		exit_game(game);
	else if (keycode == XK_w || keycode == XK_Up)
		x_dest--;
	else if (keycode == XK_a || keycode == XK_Left)
		y_dest--;
	else if (keycode == XK_s || keycode == XK_Down)
		x_dest++;
	else if (keycode == XK_d || keycode == XK_Right)
		y_dest++;
	handle_target(game, x_dest, y_dest);
	refresh_window(game);
	return (0);
}
