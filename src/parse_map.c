/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pinkdonkeyjuice <pinkdonkeyjuice@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:51:41 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/02/08 01:23:11 by pinkdonkeyj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_map(t_game *game, char *map_name)
{
	char **map;
	char *map_content;
	char *buffer;
	int	map_fd;
	int	n_read;

	buffer = (char *)malloc(sizeof(char) * 11);
	if (!buffer)
		error(game, "Error parsing the map\n");
	map_content = ft_strdup("");
	if (!map_content)
	{
		free(buffer);
		error(game, "Error\nMemory failure while parsing the map\n");
	}
	if ((map_fd = open(map_name, O_RDONLY)) == -1)
	{	
		free(buffer);
		free(map_content);
		error(game, "Error\nUnable to open the map file\nCheck that the file is present and in correct format\n");
	}
	while ((n_read = read(map_fd, buffer, 10)) != 0)
	{
		buffer[n_read] = '\0';
		map_content = ft_strjoin(map_content, buffer);
		if (!map_content)
		{
			free(buffer);
			error(game, "Error parsing the map\n");
		}
	}
	free(buffer);
	map = ft_split(map_content, '\n');
	free(map_content);
	if (!map)
		error(game, "Error parsing the map\n");
	check_map(game, map);
	game->map = map;
	game->height = get_height(map);
	game->length = ft_strlen(map[0]);
	init_position(game);
}