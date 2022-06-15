/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ba_to_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 21:01:03 by idongmin          #+#    #+#             */
/*   Updated: 2022/03/15 17:41:14 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

static void	Ba_to_b_large(t_struct *test)
{
	rra(test->A, test->command);
}

static void	Ba_to_b_medium(t_struct *test)
{
	rra(test->A, test->command);
	pb(test->A, test->B, test->command);
	rb(test->B, test->command);
}

static void	Ba_to_b_small(t_struct *test)
{
	rra(test->A, test->command);
	pb(test->A, test->B, test->command);
}

static void	Ba_to_b_recursive(t_struct *test, int start, int end)
{
	Ta_to_b(test, test->p_second, end);
	find_pivot(test, start, end);
	Bb_to_a(test, test->p_first, test->p_second - 1);
	find_pivot(test, start, end);
	Tb_to_a(test, start, test->p_first - 1);
}

void	Ba_to_b(t_struct *test, int start, int end)
{
	int		i;

	if ((end - start) <= 2)
	{
		sort_exception_handling(test, start, end, BA);
		return ;
	}
	find_pivot(test, start, end);
	i = -1;
	while (++i < (end - start + 1))
	{
		if (getLLElement(test->A, test->A->currentElementCount - 1)->data \
		>= test->array[test->p_second])
			Ba_to_b_large(test);
		else if (getLLElement(test->A, test->A->currentElementCount - 1)->data \
		< test->array[test->p_first])
			Ba_to_b_small(test);
		else
			Ba_to_b_medium(test);
	}
	Ba_to_b_recursive(test, start, end);
}
