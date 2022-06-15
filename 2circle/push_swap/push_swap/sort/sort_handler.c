/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 01:54:37 by idongmin          #+#    #+#             */
/*   Updated: 2022/03/15 17:47:04 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	sort_element_one(t_struct *test, int flag)
{
	if (flag == TA)
		return ;
	else if (flag == BA)
		rra(test->A, test->command);
	else if (flag == TB)
		pa(test->A, test->B, test->command);
	else if (flag == BB)
	{
		rrb(test->B, test->command);
		pa(test->A, test->B, test->command);
	}
}

void	sort_element_two(t_struct *test, int start, int flag)
{
	if (flag == TA)
		sort_Ta_two(test, start);
	else if (flag == BA)
		sort_Ba_two(test, start);
	else if (flag == TB)
		sort_Tb_two(test, start);
	else if (flag == BB)
		sort_Bb_two(test, start);
}

void	sort_element_three(t_struct *test, int start, int flag)
{
	if (flag == TA)
		sort_Ta_three(test, start);
	else if (flag == BA)
		sort_Ba_three(test, start);
	else if (flag == TB)
		sort_Tb_three(test, start);
	else if (flag == BB)
		sort_Bb_three(test, start);
}

void	sort_exception_handling(t_struct *test, int start, int end, int flag)
{
	if (end - start == 2)
		sort_element_three(test, start, flag);
	else if (end - start == 1)
		sort_element_two(test, start, flag);
	else if (end == start)
		sort_element_one(test, flag);
}

void	find_pivot(t_struct *test, int start, int end)
{
	if ((end - start + 1) % 3 == 2)
	{
		test->p_first = ((end - start + 1) / 3) + start;
		test->p_second = (((end - start + 1) / 3) * 2) + start + 1;
	}
	else
	{
		test->p_first = ((end - start + 1) / 3) + start;
		test->p_second = (((end - start + 1) / 3) * 2) + start;
	}
}
