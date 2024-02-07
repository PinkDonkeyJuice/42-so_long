/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyvergni <gyvergni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:51:46 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/02/06 14:56:22 by gyvergni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	refresh_window(t_game *game)
{
	//mlx_clear_window(game->mlx_id, game->mlx_window);
	render_map(game);
	return (0);
}

void	run_game(t_game *game)
{
	mlx_key_hook(game->mlx_window, &handle_keypress, game);
	mlx_hook(game->mlx_window, 17, 0L, &exit_game, game);
	mlx_loop(game->mlx_id);
}

int	main(int argc, char **argv)
{
	t_game		*game;
	t_xvar		*mlx_id;
	t_win_list	*mlx_window;

	game = malloc(sizeof(t_game));
	protect(game, "Memory allocation failure\n");
	check_args(argc, argv[1]);
	mlx_id = mlx_init();
	protect(mlx_id, "Failure to initialise game\n");
	init_game(game, mlx_id);
	parse_map(game, argv[1]);
	check(game);
	mlx_window = mlx_new_window(mlx_id, game->length * 64, game->height * 64, "so_long");
	protect(mlx_window, "Failure to create window\n");
	game->mlx_window = mlx_window;
	render_map(game);
	run_game(game);
}