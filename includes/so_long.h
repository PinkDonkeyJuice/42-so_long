/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyvergni <gyvergni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:51:34 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/02/08 15:42:54 by gyvergni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include	"../minilibx-linux/mlx.h"
# include	"unistd.h"
# include	"fcntl.h"
# include	"../minilibx-linux/mlx_int.h"
# include	"stdlib.h"

# define WALL				'1'
# define GROUND				'0'
# define PLAYER				'P'
# define CHILD				'C'
# define EXIT				'E'
# define BLOOD				'B'
# define CAR_BLOOD			'p'

typedef struct s_game
{
	int		height;
	int		length;
	int		x;
	int		y;
	int		nb_moves;
	int		nb_children;
	int		last_keypress;
	char	**map;
	void	*mlx_id;
	void	*mlx_window;
	void	*mlx_car_up;
	void	*mlx_car_down;
	void	*mlx_car_right;
	void	*mlx_car_left;
	void	*mlx_road;
	void	*mlx_wall;
	void	*mlx_child;
	void	*mlx_exit_open;
	void	*mlx_exit_close;
	void	*mlx_car_blood_left;
	void	*mlx_car_blood_right;
	void	*mlx_car_blood_up;
	void	*mlx_car_blood_down;
	void	*mlx_road_blood;
} t_game;

void	error(t_game *game, char *err_msg);
char	*ft_strdup(const char *s);
int		ft_strchr(char **tab, int c);
char	*ft_substr(char const *s, unsigned int start, int len);
int		ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, int n);
void	ft_putstr_fd(int fd, char *s);
void	check_path(char **map, t_game *game);
void	check(t_game *game);
void	free_table(char	**tab);
void	init_game(t_game *game, void *mlx_id);
void	check_args(int argc, char *map_name);
void	parse_map(t_game *game, char *map_name);
void	protect(t_game *game, void *to_test, char	*err_msg);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
int		get_height(char **map);
void	check_rectangle(t_game *game);
char	**ft_split(char const *s, char c);
void	init_position(t_game *game);
void	render_map(t_game *game);
char	*ft_itoa(int n);
void	render_sprite(t_game *game, void *mlx_img, int x, int y);
void	init_sprites(t_game *game);
int		handle_keypress(int keycode, t_game *game);
int		refresh_window(t_game *game);
int		exit_game(t_game *game);
void	free_map(char	**map);
void	free_game(t_game *game);
char	**dup_map(t_game *game, int height);
void	map_error(t_game *game, char **map, char *err_msg);

#endif