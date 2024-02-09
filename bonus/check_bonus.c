/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyvergni <gyvergni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:52:00 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/02/09 14:31:16 by gyvergni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	count_element(char **map, char element)
{
	int		nb_element;
	int		i;
	int		j;

	nb_element = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == element)
				nb_element++;
			j++;
		}
		i++;
	}
	return (nb_element);
}

void	check_positions(t_game *game, char **map, int length, int height)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'C'
				&& map[i][j] != 'P' && map[i][j] != 'E')
				map_error(game, map, "Unknown type in map\n");
			else if (map[i][j] != '1' && \
				(i == 0 || i == height - 1 || j == 0 || j == length - 1))
				map_error(game, map, "Map is not closed by walls\n");
			j++;
		}
		i++;
	}
	if (count_element(map, 'P') != 1 || count_element(map, 'E') != 1
		|| count_element(map, 'C') == 0)
		map_error(game, map, "Invalid map\n");
}

void	check_args(int argc, char *map_name)
{
	char	*ext;

	if (argc < 2)
		error(NULL, "Too few arguments");
	if (argc > 2)
		error(NULL, "Too many arguments");
	ext = ft_substr(map_name, ft_strlen(map_name) - 4, ft_strlen(map_name));
	if (ext == NULL)
		error(NULL, "Memory failure while checking arguments.\n");
	if (ft_strncmp(ext, ".ber", 4) != 0)
	{
		free(ext);
		error(NULL, "Invalid extension name for map, .ber required!");
	}
	free(ext);
}

void	check_rectangle(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) != game->length)
			map_error(game, NULL, "Invalid map : Map not rectangle\n");
		i++;
	}
}

void	check(t_game *game)
{
	char	**map_cpy;

	map_cpy = dup_map(game, game->height);
	protect(game, map_cpy, "Memory problem while checking the parameters\n");
	check_positions(game, map_cpy, game->length, game->height);
	check_path(map_cpy, game);
	free_map(map_cpy);
}
