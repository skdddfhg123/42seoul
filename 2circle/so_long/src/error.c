/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 07:30:23 by idongmin          #+#    #+#             */
/*   Updated: 2022/04/01 16:07:12 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error(char *err)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(err, 2);
	exit(EXIT_FAILURE);
}

void	error_initialization(t_game **game)
{
	(*game)->err.collect_check = 0;
	(*game)->err.element_check = 0;
	(*game)->err.is_player_exit_check = 0;
	(*game)->err.player_num_check = 0;
	(*game)->err.rectangle_check = 0;
	(*game)->err.wall_check = 0;
	(*game)->err.flag = 0;
}

void	error_print(t_game **game)
{
	ft_printf("Error\n");
	(void)game;
	if ((*game)->err.collect_check == 1)
		ft_printf("This map has no collections. Check the map.\n");
	if ((*game)->err.element_check == 1)
		ft_printf("There are some elements in the map that are not normal.\n");
	if ((*game)->err.is_player_exit_check == 1)
		ft_printf("There is no player or exit.\n");
	if ((*game)->err.player_num_check == 1)
		ft_printf("There are too many players.\n");
	if ((*game)->err.rectangle_check == 1)
		ft_printf("This map is not a rectangle.\n");
	if ((*game)->err.wall_check == 1)
		ft_printf("This map is not blocked by a wall.\n");
	exit(1);
}
