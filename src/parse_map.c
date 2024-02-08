/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyvergni <gyvergni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:51:41 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/02/08 16:23:02 by gyvergni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*concatenate_map(char *map_content, char *buffer)
{
	char	*old_content;
	char	*new_content;	

	old_content = map_content;
	new_content = ft_strjoin(old_content, buffer);
	free(old_content);
	return (new_content);
}

char	*read_map_file(t_game *game, char *map_name, \
	char *map_content, char *buffer)
{
	int	map_fd;
	int	n_read;

	map_fd = open(map_name, O_RDONLY);
	if (map_fd == -1)
	{
		free(buffer);
		free(map_content);
		error(game, "Unable to open the map file\n");
	}
	n_read = read(map_fd, buffer, 10);
	while (n_read != 0)
	{
		buffer[n_read] = '\0';
		map_content = concatenate_map(map_content, buffer);
		if (!map_content)
		{
			free(buffer);
			error(game, "Error parsing the map\n");
		}
		n_read = read(map_fd, buffer, 10);
	}
	free(buffer);
	return (map_content);
}

void	parse_map(t_game *game, char *map_name)
{
	char	*buffer;
	char	**map;
	char	*map_content;

	buffer = malloc(sizeof(char) * 11);
	protect(game, buffer, "Memory failure while parsing the map\n");
	map_content = ft_strdup("");
	if (!map_content)
	{
		free(buffer);
		error(game, "Memory failure while parsing the map\n");
	}
	map_content = read_map_file(game, map_name, map_content, buffer);
	map = ft_split(map_content, '\n');
	free(map_content);
	if (!map)
		error(game, "Error parsing the map\n");
	game->map = map;
	game->height = get_height(map);
	game->length = ft_strlen(map[0]);
	init_position(game);
	check(game);
}
