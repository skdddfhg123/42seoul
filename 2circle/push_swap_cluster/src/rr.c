/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:48:05 by idongmin          #+#    #+#             */
/*   Updated: 2022/03/15 17:56:38 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	rra(t_LinkedList *A, t_LinkedList *C)
{
	t_ListNode	tmp;

	if (A->currentElementCount == 0)
		return (EXIT_FAILURE);
	if (A->currentElementCount == 1)
		return (EXIT_SUCCESS);
	tmp.data = getLLElement(A, A->currentElementCount - 1)->data;
	removeLLElement(A, A->currentElementCount - 1);
	addLLElement(A, 0, tmp);
	tmp.data = RRA;
	addLLElement(C, 0, tmp);
	return (EXIT_SUCCESS);
}

int	rrb(t_LinkedList *B, t_LinkedList *C)
{
	t_ListNode	tmp;

	if (B->currentElementCount == 0)
		return (EXIT_FAILURE);
	if (B->currentElementCount == 1)
		return (EXIT_SUCCESS);
	tmp.data = getLLElement(B, B->currentElementCount - 1)->data;
	removeLLElement(B, B->currentElementCount - 1);
	addLLElement(B, 0, tmp);
	tmp.data = RRB;
	addLLElement(C, 0, tmp);
	return (EXIT_SUCCESS);
}

int	rrr(t_LinkedList *A, t_LinkedList *B, t_LinkedList *C)
{
	t_ListNode	command;

	if (rra(A, C) || rrb(B, C))
		return (EXIT_FAILURE);
	command.data = RRR;
	addLLElement(C, 0, command);
	return (EXIT_SUCCESS);
}
