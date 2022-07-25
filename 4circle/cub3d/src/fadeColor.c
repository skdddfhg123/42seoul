/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fadeColor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 08:19:22 by idongmin          #+#    #+#             */
/*   Updated: 2022/07/25 09:37:16 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

double	get_luminosity(t_cub *cub, double dist)
{
	static double	D;

	D = -1;
	if (D < 0)
		D = (cub->map_width + cub->map_height) / 2.0;
	if (dist > D)
		return (0);
	else
		return (1. - dist / D);
}

void	decode_color(int color, int *r, int *g, int *b)
{
	*r = color / 65536;
	color -= *r * 65536;
	*g = color / 256;
	color -= *g * 256;
	*b = color;
}

int	encode_color(int r, int g, int b)
{
	int	color;

	color = (r * 65536) + (g * 256) + (b * 1);
	return (color);
}

int	fade_color(int color, double lum)
{
	int	r;
	int	g;
	int	b;

	if (lum < 0)
		lum = 0;
	else if (lum > 1)
		lum = 1;
	decode_color(color, &r, &g, &b);
	return (encode_color((int)(r * lum), (int)(g * lum), (int)(b * lum)));
}
