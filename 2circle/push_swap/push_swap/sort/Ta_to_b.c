/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ta_to_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 02:24:00 by idongmin          #+#    #+#             */
/*   Updated: 2022/03/15 17:50:53 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

static void	Ta_to_b_large(t_struct *test)
{
	ra(test->A, test->command);
}

static void	Ta_to_b_medium(t_struct *test)
{
	pb(test->A, test->B, test->command);
	rb(test->B, test->command);
}

static void	Ta_to_b_small(t_struct *test)
{
	pb(test->A, test->B, test->command);
}

static void	Ta_to_b_recursive(t_struct *test, int start, int end)
{
	Ba_to_b(test, test->p_second, end);
	find_pivot(test, start, end);
	Bb_to_a(test, test->p_first, test->p_second - 1);
	find_pivot(test, start, end);
	Tb_to_a(test, start, test->p_first - 1);
}

void	Ta_to_b(t_struct *test, int start, int end)
{
	int		i;

	if ((end - start) <= 2)
	{
		sort_exception_handling(test, start, end, TA);
		return ;
	}
	find_pivot(test, start, end);
	i = -1;
	while (++i < (end - start + 1))
	{
		if (getLLElement(test->A, 0)->data >= test->array[test->p_second])
			Ta_to_b_large(test);
		else if (getLLElement(test->A, 0)->data < test->array[test->p_first])
			Ta_to_b_small(test);
		else
			Ta_to_b_medium(test);
	}
	Ta_to_b_recursive(test, start, end);
}
