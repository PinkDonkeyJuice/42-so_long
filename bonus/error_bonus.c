/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyvergni <gyvergni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:51:53 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/02/09 14:17:29 by gyvergni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_map(char **map)
{
	int	i;

	if (map != NULL)
	{
		i = 0;
		while (map[i])
		{
			if (map[i])
				free(map[i]);
			i++;
		}
		free(map);
	}
}

void	protect(t_game *game, void *to_test, char *err_msg)
{
	if (to_test == NULL)
		error(game, err_msg);
}

void	error(t_game *game, char *err_msg)
{
	ft_putstr_fd(2, "Error\n");
	ft_putstr_fd(2, err_msg);
	if (game != NULL)
		exit_game(game);
	exit(-1);
}

void	map_error(t_game *game, char **map, char *err_msg)
{
	free_map(map);
	error(game, err_msg);
}
