/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyvergni <gyvergni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:51:53 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/02/06 15:22:16 by gyvergni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char	**map)
{
	int	i;

	i = 0;
	while(map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	protect(void	*to_test, char	*err_msg)
{
	if (to_test == NULL)
		error(err_msg);
}

void	error(char *err_msg)
{
	ft_putstr_fd(2, "Error\n");
	ft_putstr_fd(2, err_msg);
	exit(-1);
}