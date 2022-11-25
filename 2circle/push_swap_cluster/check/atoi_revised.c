/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_revised.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 16:12:21 by dongmlee          #+#    #+#             */
/*   Updated: 2022/03/14 01:33:13 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

static int	range_check_and_add_to_a(long long result, int n_check, \
t_struct *test)
{
	if (result * n_check < -2147483648 || result * n_check > 2147483647)
		return (EXIT_FAILURE);
	test->element.data = result * n_check;
	addLLElement(test->A, test->A->currentElementCount, test->element);
	return (EXIT_SUCCESS);
}

static void	space_check(const char *str, int *i)
{
	while (str[*i] == ' ')
		(*i)++;
}

static int	sign_check(const char *str, int *i)
{
	int		n_check;

	n_check = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			n_check *= -1;
		(*i)++;
	}
	return (n_check);
}

int	ft_atoi_revised(const char *str, t_struct *test)
{
	int			i;
	int			n_check;
	long long	result;

	i = 0;
	if (!str[i])
		return (EXIT_FAILURE);
	while (str[i])
	{
		result = 0;
		space_check(str, &i);
		n_check = sign_check(str, &i);
		if (str[i] < '0' || str[i] > '9')
			return (EXIT_FAILURE);
		while (str[i] && str[i] >= '0' && str[i] <= '9')
			result = (result * 10) + (str[i++] - '0');
		if (!(str[i] == ' ') && str[i])
			return (EXIT_FAILURE);
		if (range_check_and_add_to_a(result, n_check, test))
			return (EXIT_FAILURE);
		space_check(str, &i);
	}
	return (EXIT_SUCCESS);
}
