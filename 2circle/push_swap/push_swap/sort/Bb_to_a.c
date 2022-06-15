/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bb_to_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 21:05:45 by idongmin          #+#    #+#             */
/*   Updated: 2022/03/15 17:41:46 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

static void	Bb_to_a_large(t_struct *test)
{
	rrb(test->B, test->command);
	pa(test->A, test->B, test->command);
}

static void	Bb_to_a_medium(t_struct *test)
{
	rrb(test->B, test->command);
	pa(test->A, test->B, test->command);
	ra(test->A, test->command);
}

static void	Bb_to_a_small(t_struct *test)
{
	rrb(test->B, test->command);
}

static void	Bb_to_a_recursive(t_struct *test, int start, int end)
{
	Ta_to_b(test, test->p_second, end);
	find_pivot(test, start, end);
	Ba_to_b(test, test->p_first, test->p_second - 1);
	find_pivot(test, start, end);
	Tb_to_a(test, start, test->p_first - 1);
}

void	Bb_to_a(t_struct *test, int start, int end)
{
	int		i;

	if ((end - start) <= 2)
	{
		sort_exception_handling(test, start, end, BB);
		return ;
	}
	find_pivot(test, start, end);
	i = -1;
	while (++i < (end - start + 1))
	{
		if (getLLElement(test->B, test->B->currentElementCount - 1)->data \
		>= test->array[test->p_second])
			Bb_to_a_large(test);
		else if (getLLElement(test->B, test->B->currentElementCount - 1)->data \
		< test->array[test->p_first])
			Bb_to_a_small(test);
		else
			Bb_to_a_medium(test);
	}
	Bb_to_a_recursive(test, start, end);
}
