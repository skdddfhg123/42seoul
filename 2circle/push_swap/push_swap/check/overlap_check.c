/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overlap_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 23:02:25 by idongmin          #+#    #+#             */
/*   Updated: 2022/03/15 20:19:45 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	array_sort_and_overlap_check(t_struct *test)
{
	long long	tmp;
	int			i;
	int			j;

	j = test->A->currentElementCount;
	while (j != 0)
	{
		i = 1;
		while (i < j)
		{
			tmp = test->array[i - 1];
			if (tmp == test->array[i])
				ft_error();
			if (tmp > test->array[i])
			{
				test->array[i - 1] = test->array[i];
				test->array[i] = tmp;
			}
			i++;
		}
		j--;
	}
}
