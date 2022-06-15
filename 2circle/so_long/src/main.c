/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 00:58:06 by idongmin          #+#    #+#             */
/*   Updated: 2022/04/01 16:40:25 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	initialization(t_game *game)
{
	game->step = 0;
	game->x = 0;
	game->y = 0;
	game->exit_x = 0;
	game->exit_y = 0;
	game->img.width = 32;
	game->img.height = 32;
	game->img.player_flag = KEY_DOWN;
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (!make_map(argc, argv, &game))
		return (1);
	initialization(game);
	insert_player(game);
	insert_window(game);
	insert_image(game);
	draw_map(game);
	loop(game);
}
