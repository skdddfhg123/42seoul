/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathUtil.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 02:10:27 by idongmin          #+#    #+#             */
/*   Updated: 2022/07/25 07:25:42 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

double	is_zero(double d)
{
	return (fabs(d) < EPS);
}

double	deg2rad(double d)
{
	return (d * M_PI / 180.0);
}

double	rad2deg(double d)
{
	return (d * 180.0 / M_PI);
}

double	FOV_H(void)
{
	return (deg2rad(FOV));
}

double	FOV_V(void)
{
	return (FOV_H() * (double)SY / (double)SX);
}
