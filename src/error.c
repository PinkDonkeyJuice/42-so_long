/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pinkdonkeyjuice <pinkdonkeyjuice@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:51:53 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/02/08 01:31:25 by pinkdonkeyj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;
	
	if (map != NULL)
	{
		i = 0;
		while(map[i])
		{
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
		free_game(game);
	exit(-1);
}