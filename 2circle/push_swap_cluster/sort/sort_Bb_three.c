/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_Bb_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 02:56:55 by idongmin          #+#    #+#             */
/*   Updated: 2022/03/15 17:45:30 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

static int	Bb_order_check(t_struct *test, int start, int position)
{
	int		flag;

	flag = 0;
	if (getLLElement(test->B, position)->data == test->array[start])
	{
		if (getLLElement(test->B, position + 1)->data == test->array[start + 1])
			flag = 1;
		else
			flag = 2;
	}
	else if (getLLElement(test->B, position)->data == test->array[start + 1])
	{
		if (getLLElement(test->B, position + 1)->data == test->array[start])
			flag = 3;
		else
			flag = 4;
	}
	else
	{
		if (getLLElement(test->B, position + 1)->data == test->array[start])
			flag = 5;
		else
			flag = 6;
	}
	return (flag);
}

static void	flag_1_2(t_struct *test, int flag)
{
	if (flag == 1)
	{
		rrb(test->B, test->command);
		pa(test->A, test->B, test->command);
		rrb(test->B, test->command);
		pa(test->A, test->B, test->command);
		rrb(test->B, test->command);
		pa(test->A, test->B, test->command);
	}
	else if (flag == 2)
	{
		rrb(test->B, test->command);
		rrb(test->B, test->command);
		pa(test->A, test->B, test->command);
		pa(test->A, test->B, test->command);
		rrb(test->B, test->command);
		pa(test->A, test->B, test->command);
	}
}

static void	flag_3_4(t_struct *test, int flag)
{
	if (flag == 3)
	{
		rrb(test->B, test->command);
		pa(test->A, test->B, test->command);
		rrb(test->B, test->command);
		rrb(test->B, test->command);
		pa(test->A, test->B, test->command);
		pa(test->A, test->B, test->command);
	}
	else if (flag == 4)
	{
		rrb(test->B, test->command);
		rrb(test->B, test->command);
		pa(test->A, test->B, test->command);
		rrb(test->B, test->command);
		pa(test->A, test->B, test->command);
		pa(test->A, test->B, test->command);
	}
}

static void	flag_5_6(t_struct *test, int flag)
{
	if (flag == 5)
	{
		rrb(test->B, test->command);
		rrb(test->B, test->command);
		rrb(test->B, test->command);
		pa(test->A, test->B, test->command);
		sb(test->B, test->command);
		pa(test->A, test->B, test->command);
		pa(test->A, test->B, test->command);
	}
	else if (flag == 6)
	{
		rrb(test->B, test->command);
		rrb(test->B, test->command);
		rrb(test->B, test->command);
		pa(test->A, test->B, test->command);
		pa(test->A, test->B, test->command);
		pa(test->A, test->B, test->command);
	}
}

void	sort_Bb_three(t_struct *test, int start)
{
	int	flag;

	flag = Bb_order_check(test, start, test->B->currentElementCount - 3);
	flag_1_2(test, flag);
	flag_3_4(test, flag);
	flag_5_6(test, flag);
	return ;
}
