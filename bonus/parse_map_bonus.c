/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyvergni <gyvergni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:51:41 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/02/09 14:18:04 by gyvergni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*concatenate_map(char *map_content, char *buffer, t_game *game)
{
	char	*new_content;	

	new_content = ft_strjoin(map_content, buffer);
	if (new_content == NULL)
	{
		free(map_content);
		free(buffer);
		error(game, "Memory failure while parsing the map\n");
	}
	free(map_content);
	return (new_content);
}

void	read_error(t_game *game, char *map_content, char *buffer)
{
	if (buffer)
		free(buffer);
	if (map_content)
		free(map_content);
	error(game, "Encountered while reading the map file\n");
}

char	*read_map_file(t_game *game, char *map_name, \
	char *map_content, char *buffer)
{
	int	map_fd;
	int	n_read;

	map_fd = open(map_name, O_RDONLY);
	if (map_fd == -1)
		read_error(game, map_content, buffer);
	n_read = read(map_fd, buffer, 10);
	while (n_read != 0)
	{
		if (n_read == -1 || buffer == NULL)
			read_error(game, map_content, buffer);
		buffer[n_read] = '\0';
		map_content = concatenate_map(map_content, buffer, game);
		if (!map_content)
			read_error(game, map_content, buffer);
		n_read = read(map_fd, buffer, 10);
	}
	if (close(map_fd) == -1)
		read_error(game, map_content, buffer);
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
	check_rectangle(game);
	init_position(game);
	check(game);
}
