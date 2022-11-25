/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 10:25:48 by idongmin          #+#    #+#             */
/*   Updated: 2022/04/01 11:35:00 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_player_exit_check(t_game **game)
{
	size_t	i;
	int		p_check;
	int		e_check;

	i = -1;
	p_check = 0;
	e_check = 0;
	while (++i < (*game)->map_h)
	{
		if (ft_strchr((*game)->map[i], 'P'))
			p_check++;
		if (ft_strchr((*game)->map[i], 'E'))
			e_check++;
	}
	if (p_check >= 2)
	{
		(*game)->err.flag = 1;
		(*game)->err.player_num_check = 1;
	}
	if (!p_check || !e_check)
	{
		(*game)->err.flag = 1;
		return (0);
	}
	return (1);
}

int	rectangle_check(t_game **game)
{
	size_t	len_check;
	size_t	i;

	i = 0;
	len_check = ft_strlen((*game)->map[i]);
	if (len_check == 0)
		error("The width of the map is 0.\n");
	while (i < (*game)->map_h)
	{
		if (len_check != ft_strlen((*game)->map[i]))
		{
			(*game)->err.flag = 1;
			return (0);
		}
		i++;
	}
	return (1);
}

static int	is_wall(char *s)
{
	size_t	cnt;

	cnt = 0;
	while (s[cnt] == '1')
		cnt++;
	return (ft_strlen(s) == cnt);
}

int	wall_check(t_game **game)
{
	size_t	i;
	int		flag;

	i = -1;
	flag = 0;
	if (!is_wall((*game)->map[0]))
		flag = 1;
	if (!is_wall((*game)->map[(*game)->map_h - 1]))
		flag = 1;
	while (++i < (*game)->map_h)
	{
		if ((*game)->map[i][0] != '1')
			flag = 1;
		if ((*game)->map[i][ft_strlen((*game)->map[i]) - 1] != '1')
			flag = 1;
	}
	if (flag)
	{
		(*game)->err.flag = 1;
		return (0);
	}
	return (1);
}
