/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_Ta_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 02:37:55 by idongmin          #+#    #+#             */
/*   Updated: 2022/03/15 17:47:56 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	Ta_order_check(t_struct *test, int start, int position)
{
	int		flag;

	flag = 0;
	if (getLLElement(test->A, position)->data == test->array[start])
	{
		if (getLLElement(test->A, position + 1)->data == test->array[start + 1])
			flag = 1;
		else
			flag = 2;
	}
	else if (getLLElement(test->A, position)->data == test->array[start + 1])
	{
		if (getLLElement(test->A, position + 1)->data == test->array[start])
			flag = 3;
		else
			flag = 4;
	}
	else
	{
		if (getLLElement(test->A, position + 1)->data == test->array[start])
			flag = 5;
		else
			flag = 6;
	}
	return (flag);
}

static void	flag_1_2(t_struct *test, int flag)
{
	if (flag == 1)
		return ;
	else if (flag == 2)
	{
		ra(test->A, test->command);
		sa(test->A, test->command);
		rra(test->A, test->command);
	}
}

static void	flag_3_4(t_struct *test, int flag)
{
	if (flag == 3)
		sa(test->A, test->command);
	else if (flag == 4)
	{
		ra(test->A, test->command);
		ra(test->A, test->command);
		pb(test->A, test->B, test->command);
		rra(test->A, test->command);
		rra(test->A, test->command);
		pa(test->A, test->B, test->command);
	}
}

static void	flag_5_6(t_struct *test, int flag)
{
	if (flag == 5)
	{
		pb(test->A, test->B, test->command);
		ra(test->A, test->command);
		pa(test->A, test->B, test->command);
		sa(test->A, test->command);
		rra(test->A, test->command);
	}
	else if (flag == 6)
	{
		sa(test->A, test->command);
		pb(test->A, test->B, test->command);
		sa(test->A, test->command);
		pa(test->A, test->B, test->command);
		sa(test->A, test->command);
	}
}

void	sort_Ta_three(t_struct *test, int start)
{
	int	flag;

	flag = Ta_order_check(test, start, 0);
	flag_1_2(test, flag);
	flag_3_4(test, flag);
	flag_5_6(test, flag);
	return ;
}
