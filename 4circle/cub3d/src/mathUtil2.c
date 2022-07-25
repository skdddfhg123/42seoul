/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathUtil2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 02:16:23 by idongmin          #+#    #+#             */
/*   Updated: 2022/07/25 07:37:54 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

double	ANGLE_PER_PIXEL(void)
{
	return (FOV_H() / (SX - 1.));
}

double	HALF_FOV_H(void)
{
	return (FOV_H() / 2.0);
}

double	_2PI(void)
{
	return (M_PI * 2);
}

int	min(int x, int y)
{
	if (x < y)
		return (x);
	else
		return (y);
}

int	max(int x, int y)
{
	if (x > y)
		return (x);
	else
		return (y);
}
