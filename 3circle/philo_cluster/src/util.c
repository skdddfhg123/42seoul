/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 11:47:01 by idongmin          #+#    #+#             */
/*   Updated: 2022/04/16 02:12:43 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (c);
	return (0);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

static int	check_over_range(unsigned long long result, int n_check)
{
	if (result > LLONG_MAX - 1 && n_check == -1)
		return (0);
	if (result > LLONG_MAX && n_check == 1)
		return (-1);
	return (result * n_check);
}

int	ft_atoi(const char *str)
{
	int					i;
	int					n_check;
	unsigned long long	result;

	i = 0;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	n_check = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n_check *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (check_over_range(result, n_check));
}
