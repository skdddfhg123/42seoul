/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 10:54:30 by idongmin          #+#    #+#             */
/*   Updated: 2022/04/01 16:38:49 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	draw_map(t_game *game)
{
	size_t	i;
	size_t	j;

	if (!game->win)
		return (1);
	i = -1;
	while (++i < game->map_h)
	{
		j = -1;
		while (++j < game->map_w)
			parse_image(game, i, j);
	}
	return (0);
}

static int	exit_game(void)
{
	ft_printf("Red Cross Check\n");
	exit(1);
}

void	loop(t_game *game)
{
	mlx_loop_hook(game->mlx, &draw_map, game);
	mlx_hook(game->win, KEY_PRESS, 0, &key_press, game);
	mlx_hook(game->win, 17, 0, &exit_game, game);
	mlx_clear_window(game->mlx, game->win);
	mlx_loop(game->mlx);
}

void	parse_image(t_game *game, int i, int j)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img.tile,
		j * game->img.width, i * game->img.height);
	if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img.wall,
			j * game->img.width, i * game->img.height);
	else if (game->map[i][j] == 'P' && game->img.player_flag == KEY_UP)
		mlx_put_image_to_window(game->mlx, game->win, game->img.player_b,
			j * game->img.width, i * game->img.height);
	else if (game->map[i][j] == 'P' && game->img.player_flag == KEY_DOWN)
		mlx_put_image_to_window(game->mlx, game->win, game->img.player_f,
			j * game->img.width, i * game->img.height);
	else if (game->map[i][j] == 'P' && game->img.player_flag == KEY_RIGHT)
		mlx_put_image_to_window(game->mlx, game->win, game->img.player_r,
			j * game->img.width, i * game->img.height);
	else if (game->map[i][j] == 'P' && game->img.player_flag == KEY_LEFT)
		mlx_put_image_to_window(game->mlx, game->win, game->img.player_l,
			j * game->img.width, i * game->img.height);
	else if (game->map[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img.exit,
			j * game->img.width, i * game->img.height);
	else if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->img.collect,
			j * game->img.width, i * game->img.height);
}
