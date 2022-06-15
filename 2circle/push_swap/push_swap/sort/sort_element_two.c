/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_element_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 06:41:32 by idongmin          #+#    #+#             */
/*   Updated: 2022/03/15 18:16:57 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	sort_Ta_two(t_struct *test, int start)
{
	if (getLLElement(test->A, 0)->data == test->array[start + 1])
		sa(test->A, test->command);
}

void	sort_Ba_two(t_struct *test, int start)
{
	if (getLLElement(test->A, test->A->currentElementCount - 2)->data == \
	test->array[start])
	{
		rra(test->A, test->command);
		rra(test->A, test->command);
	}
	else
	{
		rra(test->A, test->command);
		rra(test->A, test->command);
		sa(test->A, test->command);
	}
}

void	sort_Tb_two(t_struct *test, int start)
{
	if (getLLElement(test->B, 0)->data == test->array[start])
	{
		sb(test->B, test->command);
		pa(test->A, test->B, test->command);
		pa(test->A, test->B, test->command);
	}
	else
	{
		pa(test->A, test->B, test->command);
		pa(test->A, test->B, test->command);
	}
}

void	sort_Bb_two(t_struct *test, int start)
{
	if (getLLElement(test->B, test->B->currentElementCount - 2)->data == \
	test->array[start])
	{
		rrb(test->B, test->command);
		pa(test->A, test->B, test->command);
		rrb(test->B, test->command);
		pa(test->A, test->B, test->command);
	}
	else
	{
		rrb(test->B, test->command);
		rrb(test->B, test->command);
		pa(test->A, test->B, test->command);
		pa(test->A, test->B, test->command);
	}
}
