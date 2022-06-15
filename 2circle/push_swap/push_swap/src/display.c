/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:23:28 by idongmin          #+#    #+#             */
/*   Updated: 2022/03/15 20:17:45 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

static void	push_command(int cmd)
{
	if (cmd == PA)
		ft_printf("pa\n");
	else if (cmd == PB)
		ft_printf("pb\n");
	else if (cmd == SA)
		ft_printf("sa\n");
	else if (cmd == SB)
		ft_printf("sb\n");
	else if (cmd == RA)
		ft_printf("ra\n");
	else if (cmd == RB)
		ft_printf("rb\n");
	else if (cmd == RRA)
		ft_printf("rra\n");
	else if (cmd == RRB)
		ft_printf("rrb\n");
}

static void	compare_command(int next, int cmd, int *total)
{
	if ((next == RA && cmd == RRA) || (next == RRA && cmd == RA) || \
		(next == RB && cmd == RRB) || (next == RRB && cmd == RB) || \
		(next == PA && cmd == PB) || (next == PB && cmd == PA) || \
		(next == SA && cmd == SA) || (next == SB && cmd == SB))
		(*total) -= 1;
	else if ((next == RA && cmd == RB) || (next == RB && cmd == RA))
	{
		(*total) -= 1;
		ft_printf("rr\n");
	}
	else if ((next == RRA && cmd == RRB) || (next == RRB && cmd == RRA))
	{
		(*total) -= 1;
		ft_printf("rrr\n");
	}
	else if ((next == SA && cmd == SB) || (next == SB && cmd == SA))
	{
		(*total) -= 1;
		ft_printf("ss\n");
	}
	else
		push_command(cmd);
}

void	dispay_command(t_struct *test)
{
	int		total;
	int		cmd;
	int		next;

	total = test->command->currentElementCount;
	if (total == 0)
		return ;
	next = 0;
	while (total--)
	{
		cmd = getLLElement(test->command, total)->data;
		if (total > 1)
			next = getLLElement(test->command, total - 1)->data;
		else
			next = 0;
		compare_command(next, cmd, &total);
	}
}
