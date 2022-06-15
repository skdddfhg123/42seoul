/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_element_handler.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:02:32 by idongmin          #+#    #+#             */
/*   Updated: 2022/03/15 17:42:52 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"
#include <stdio.h>

static void	short_element_three(t_struct *test, int start)
{
	int		flag;

	flag = Ta_order_check(test, start, 0);
	if (flag == 2)
	{
		sa(test->A, test->command);
		ra(test->A, test->command);
	}
	else if (flag == 3)
		sa(test->A, test->command);
	else if (flag == 4)
		rra(test->A, test->command);
	else if (flag == 5)
		ra(test->A, test->command);
	else if (flag == 6)
	{
		sa(test->A, test->command);
		rra(test->A, test->command);
	}
}

void	element_five(t_struct *test)
{
	int		i;

	i = -1;
	while (++i < 5)
	{
		if (getLLElement(test->A, 0)->data <= test->array[1])
			pb(test->A, test->B, test->command);
		else
			ra(test->A, test->command);
	}
	short_element_three(test, 2);
	if (getLLElement(test->B, 0)->data == test->array[0])
		sb(test->B, test->command);
	pa(test->A, test->B, test->command);
	pa(test->A, test->B, test->command);
}

static void	Ta_to_b_medium(t_struct *test)
{
	pb(test->A, test->B, test->command);
	rb(test->B, test->command);
}

static void	S_Ta_to_b(t_struct *test, int start, int end)
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
			ra(test->A, test->command);
		else if (getLLElement(test->A, 0)->data < test->array[test->p_first])
			pb(test->A, test->B, test->command);
		else
			Ta_to_b_medium(test);
	}
	S_Ta_to_b(test, test->p_second, end);
	find_pivot(test, start, end);
	Bb_to_a(test, test->p_first, test->p_second - 1);
	find_pivot(test, start, end);
	Tb_to_a(test, start, test->p_first - 1);
}

void	short_element_handler(t_struct *test, int start, int end)
{
	if (end - start == 1 && getLLElement(test->A, 0)->data == test->array[1])
		ra(test->A, test->command);
	else if (end - start == 2)
		short_element_three(test, 0);
	else if (end - start == 4)
		element_five(test);
	else
		S_Ta_to_b(test, start, end);
}
