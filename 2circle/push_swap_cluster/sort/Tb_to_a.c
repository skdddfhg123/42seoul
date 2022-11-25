/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tb_to_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 21:10:03 by idongmin          #+#    #+#             */
/*   Updated: 2022/03/15 17:51:11 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

static void	Tb_to_a_large(t_struct *test)
{
	pa(test->A, test->B, test->command);
}

static void	Tb_to_a_medium(t_struct *test)
{
	pa(test->A, test->B, test->command);
	ra(test->A, test->command);
}

static void	Tb_to_a_small(t_struct *test)
{
	rb(test->B, test->command);
}

static void	Tb_to_a_recursive(t_struct *test, int start, int end)
{
	Ta_to_b(test, test->p_second, end);
	find_pivot(test, start, end);
	Ba_to_b(test, test->p_first, test->p_second - 1);
	find_pivot(test, start, end);
	Bb_to_a(test, start, test->p_first - 1);
}

void	Tb_to_a(t_struct *test, int start, int end)
{
	int		i;

	if ((end - start) <= 2)
	{
		sort_exception_handling(test, start, end, TB);
		return ;
	}
	find_pivot(test, start, end);
	i = -1;
	while (++i < (end - start + 1))
	{
		if (getLLElement(test->B, 0)->data >= test->array[test->p_second])
			Tb_to_a_large(test);
		else if (getLLElement(test->B, 0)->data < test->array[test->p_first])
			Tb_to_a_small(test);
		else
			Tb_to_a_medium(test);
	}
	Tb_to_a_recursive(test, start, end);
}
