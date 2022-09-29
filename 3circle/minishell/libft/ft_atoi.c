/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woon <woon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 06:15:23 by chaewkim          #+#    #+#             */
/*   Updated: 2022/02/16 20:32:34 by woon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *str)
{
	int			sign;
	int			i;
	long long	num;
	long long	tmp;

	sign = 1;
	num = 0;
	i = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (is_digit(str[i]))
	{
		tmp = num * 10 + str[i] - '0';
		if (tmp < num)
			return ((sign + 1) / -2);
		num = tmp;
		i++;
	}
	return ((int)num * sign);
}
