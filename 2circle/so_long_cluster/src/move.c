/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 10:52:56 by idongmin          #+#    #+#             */
/*   Updated: 2022/04/01 16:40:08 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	exit_move(int flag, t_game *game)
{
	if ((game->collect != 0) && \
	((flag == KEY_UP && game->map[game->y - 1][game->x] == 'E')
		|| (flag == KEY_DOWN && game->map[game->y + 1][game->x] == 'E')
		|| (flag == KEY_RIGHT && game->map[game->y][game->x + 1] == 'E')
		|| (flag == KEY_LEFT && game->map[game->y][game->x - 1] == 'E')))
	{
		game->exit_x = game->x;
		game->exit_y = game->y;
	}
}

int	next_tile_check(int flag, t_game *game)
{
	if ((flag == KEY_UP && game->map[game->y - 1][game->x] == '1')
		|| (flag == KEY_DOWN && game->map[game->y + 1][game->x] == '1')
		|| (flag == KEY_RIGHT && game->map[game->y][game->x + 1] == '1')
		|| (flag == KEY_LEFT && game->map[game->y][game->x - 1] == '1'))
	{
		mlx_clear_window(game->mlx, game->win);
		draw_map(game);
		return (EXIT_FAILURE);
	}
	if ((game->collect == 0) && \
	((flag == KEY_UP && game->map[game->y - 1][game->x] == 'E')
		|| (flag == KEY_DOWN && game->map[game->y + 1][game->x] == 'E')
		|| (flag == KEY_RIGHT && game->map[game->y][game->x + 1] == 'E')
		|| (flag == KEY_LEFT && game->map[game->y][game->x - 1] == 'E')))
	{
		ft_printf("CLEAR !!!\n");
		exit(1);
	}
	if ((flag == KEY_UP && game->map[game->y - 1][game->x] == 'C')
		|| (flag == KEY_DOWN && game->map[game->y + 1][game->x] == 'C')
		|| (flag == KEY_RIGHT && game->map[game->y][game->x + 1] == 'C')
		|| (flag == KEY_LEFT && game->map[game->y][game->x - 1] == 'C'))
		game->collect--;
	return (EXIT_SUCCESS);
}

void	move_player(int flag, t_game *game)
{
	game->img.player_flag = flag;
	if (next_tile_check(flag, game))
		return ;
	game->step++;
	if (game->exit_x != 0)
	{
		game->map[game->y][game->x] = 'E';
		game->exit_x = 0;
	}
	else
		game->map[game->y][game->x] = '0';
	exit_move(flag, game);
	if (flag == KEY_UP)
		game->y -= 1;
	else if (flag == KEY_DOWN)
		game->y += 1;
	else if (flag == KEY_RIGHT)
		game->x += 1;
	else if (flag == KEY_LEFT)
		game->x -= 1;
	game->map[game->y][game->x] = 'P';
	mlx_clear_window(game->mlx, game->win);
	draw_map(game);
	ft_printf("STEP = %d, (%d, %d)\n", game->step, game->x, game->y);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == KEY_W || keycode == KEY_UP)
		move_player(KEY_UP, game);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_player(KEY_DOWN, game);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_player(KEY_RIGHT, game);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move_player(KEY_LEFT, game);
	return (0);
}
