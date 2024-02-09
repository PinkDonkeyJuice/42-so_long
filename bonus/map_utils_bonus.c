/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyvergni <gyvergni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:50:24 by gyvergni          #+#    #+#             */
/*   Updated: 2024/02/09 14:18:00 by gyvergni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	**dup_map(t_game *game, int height)
{
	int		i;
	char	**map_cpy;

	i = 0;
	map_cpy = malloc(sizeof(char *) * (height + 1));
	protect(game, map_cpy, "Memory problem while checking the parameters\n");
	while (i < height)
	{
		map_cpy[i] = ft_strdup(game->map[i]);
		if (map_cpy[i] == NULL)
		{
			free_map(map_cpy);
			error(game, "Memory problem while checking the parameters\n");
		}
		i++;
	}
	map_cpy[i] = NULL;
	return (map_cpy);
}

int	get_height(char **map)
{
	int	height;

	height = 0;
	while (map[height])
		height++;
	return (height);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen((char *)s);
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	ft_strchr(char **tab, int c)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == (char)c)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
