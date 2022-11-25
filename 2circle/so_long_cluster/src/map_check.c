/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 07:30:27 by idongmin          #+#    #+#             */
/*   Updated: 2022/04/01 10:58:53 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	collect_check(t_game **game)
{
	size_t	i;
	size_t	j;
	int		cnt;

	i = -1;
	cnt = 0;
	while (++i < (*game)->map_h)
	{
		j = -1;
		while (++j < (*game)->map_w)
		{
			if ((*game)->map[i][j] == 'C')
				cnt++;
		}
	}
	if (cnt)
	{
		(*game)->collect = cnt;
		return (1);
	}
	(*game)->err.flag = 1;
	return (0);
}

int	element_check(t_game **game)
{
	size_t	i;
	size_t	j;
	char	tmp;

	i = 0;
	while (i < (*game)->map_h)
	{
		j = 0;
		while (j < (*game)->map_w)
		{
			tmp = (*game)->map[i][j++];
			if (tmp == '0' || tmp == '1' || tmp == 'E' || \
			tmp == 'C' || tmp == 'P')
				continue ;
			else
			{
				(*game)->err.flag = 1;
				return (0);
			}
		}
		i++;
	}
	return (1);
}

int	check_map_data(t_game **game)
{
	error_initialization(game);
	if (!collect_check(game))
		(*game)->err.collect_check = 1;
	if (!element_check(game))
		(*game)->err.element_check = 1;
	if (!is_player_exit_check(game))
		(*game)->err.is_player_exit_check = 1;
	if (!rectangle_check(game))
		(*game)->err.rectangle_check = 1;
	if (!wall_check(game))
		(*game)->err.wall_check = 1;
	if ((*game)->err.flag == 1)
		error_print(game);
	return (1);
}
