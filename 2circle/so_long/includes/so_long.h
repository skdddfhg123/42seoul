/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:23:43 by idongmin          #+#    #+#             */
/*   Updated: 2022/04/01 12:22:02 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../lib/include/ft_printf.h"
# include "../lib/include/get_next_line.h"
# include "../lib/include/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_error
{
	int		rectangle_check;
	int		element_check;
	int		player_num_check;
	int		is_player_exit_check;
	int		collect_check;
	int		wall_check;
	int		flag;
}			t_error;

typedef struct s_img
{
	void	*mlx_img;
	void	*wall;
	void	*exit;
	void	*tile;
	void	*player_f;
	void	*player_b;
	void	*player_r;
	void	*player_l;
	void	*collect;
	int		width;
	int		height;
	int		player_flag;
}				t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	size_t	map_h;
	size_t	map_w;
	int		collect;
	int		exit;
	int		exit_x;
	int		exit_y;
	int		x;
	int		y;
	int		step;
	t_img	img;
	t_error	err;
}			t_game;

void	error(char *err);
void	error_initialization(t_game **game);
void	error_print(t_game **game);

int		check_filename(char *file_name);
void	get_map_height_and_malloc_map(char *file_name, t_game **game);
int		read_map_file(char *file_name, t_game **game);
int		make_map(int argc, char **argv, t_game **game);

int		check_map_data(t_game **game);
int		is_player_exit_check(t_game **game);
int		rectangle_check(t_game **game);
int		wall_check(t_game **game);
int		collect_check(t_game **game);
int		element_check(t_game **game);

void	insert_player(t_game *game);
void	insert_window(t_game *game);
void	insert_image(t_game *game);

void	exit_move(int flag, t_game *game);
int		next_tile_check(int flag, t_game *game);
void	move_player(int flag, t_game *game);
int		key_press(int keycode, t_game *game);

void	parse_image(t_game *game, int i, int j);
int		draw_map(t_game *game);
void	loop(t_game *game);

# define KEY_PRESS	2

# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_ESC	53
# define KEY_UP		126
# define KEY_LEFT	123
# define KEY_DOWN	125
# define KEY_RIGHT	124

#endif