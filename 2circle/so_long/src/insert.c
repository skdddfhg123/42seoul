/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 10:47:24 by idongmin          #+#    #+#             */
/*   Updated: 2022/04/01 12:19:39 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	insert_player(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < game->map_h)
	{
		j = 0;
		while (j < game->map_w)
		{
			if (game->map[i][j] == 'P')
			{
				game->x = (int)j;
				game->y = (int)i;
			}
			j++;
		}
		i++;
	}
}

void	insert_window(t_game *game)
{
	int	width;
	int	height;

	width = game->map_w * game->img.width;
	height = game->map_h * game->img.height;
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		error("mlx init error\n");
	game->win = mlx_new_window(game->mlx, width, height, "dongmlee so_long");
	if (!game->win)
		error("mlx window error\n");
}

void	insert_image(t_game *game)
{
	game->img.tile = mlx_xpm_file_to_image(game->mlx, "textures/tile02.xpm", \
		&game->img.width, &game->img.height);
	game->img.exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", \
		&game->img.width, &game->img.height);
	game->img.player_f = mlx_xpm_file_to_image(game->mlx, "textures/front.xpm", \
		&game->img.width, &game->img.height);
	game->img.player_b = mlx_xpm_file_to_image(game->mlx, "textures/back.xpm", \
		&game->img.width, &game->img.height);
	game->img.player_r = mlx_xpm_file_to_image(game->mlx, "textures/right.xpm", \
		&game->img.width, &game->img.height);
	game->img.player_l = mlx_xpm_file_to_image(game->mlx, "textures/left.xpm", \
		&game->img.width, &game->img.height);
	game->img.wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", \
		&game->img.width, &game->img.height);
	game->img.collect = mlx_xpm_file_to_image(game->mlx, \
	"textures/collect01.xpm", &game->img.width, &game->img.height);
}
