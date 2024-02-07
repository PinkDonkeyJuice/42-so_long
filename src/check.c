/* ************************************************************************** */
/*                                 maxColsint                                           */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pinkdonkeyjuice <pinkdonkeyjuice@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:52:00 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/02/01 18:13:39 by pinkdonkeyj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_positions(char **map, int length, int height)
{
	int	i;
	int	j;
	int	nb_player;
	int	nb_collectible;
	int	nb_exit;

	i = 0;
	nb_player = 0;
	nb_collectible = 0;
	nb_exit = 0;
	while (map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if (map[i][j] == 'P')
				nb_player++;
			else if (map[i][j] == 'C')
				nb_collectible++;
			else if (map[i][j] == 'E')
				nb_exit++;
			else if (map[i][j] != '1' && map[i][j] != '0')
				error("Unknown type in map\n");
			else if (map[i][j] != '1' && (i == 0 || i == height - 1 || j == 0 || j == length - 1))
				error("Map is not closed by walls\n");
			j++;
		}
		i++;
	}
	if (nb_collectible == 0 || nb_exit != 1 || nb_player != 1)
		error("Invalid map\n");
}

#include "stdio.h"

void	check_args(int argc, char *map_name)
{
	char	*ext;

	ext = ft_substr(map_name, ft_strlen(map_name) - 4, ft_strlen(map_name));
	if (ft_strncmp(ext, ".ber", 4) != 0)
	{
		free(ext);
		error("Invalid extension name for map, .ber required!");
	}
	if (argc < 2)
		error("Too few arguments, need to provide map with .ber extension as argument");
	if (argc > 2)
		error("Too many arguments, need to provide only map with .ber extension as argument");
}

void	check_map(char **map)
{
	int	length;
	int height;
	int	i;

	i = 0;
	length = ft_strlen(map[0]);
	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) != length)
			error("Invalid map : Map not rectangle\n");
		i++;
	}
	height = ft_strlen(map[0]);
	check_positions(map, length, height);
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	while(map[i])
	{
		printf("Line %d is %s\n", i , map[i]);
		i++;
	}
}

char	**dup_map(char **map, int height)
{
	int		i;
	char	**map_cpy;
	
	i = 0;
	map_cpy = malloc(sizeof(char *) * (height + 1));
	if (map_cpy == NULL)
		error("Memory problem while checking the parameters\n");
	while (i < height)
	{
		map_cpy[i] = ft_strdup(map[i]);
		if (map_cpy[i] == NULL)
		{
			free_map(map_cpy);
			error("Memory problem while checking the parameters\n");
		}
		i++;
	}
	map_cpy[i] = NULL;
	return(map_cpy);
}

void	check(t_game *game)
{
	char **map_cpy;

	map_cpy = dup_map(game->map, game->height);
	protect(map_cpy, "Memory problem while checking the parameters\n");
	check_positions(map_cpy, game->length, game->height);
	check_path(map_cpy, game);
}
