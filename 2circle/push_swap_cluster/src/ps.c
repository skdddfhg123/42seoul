/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:43:49 by idongmin          #+#    #+#             */
/*   Updated: 2022/03/15 19:00:59 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	pa(t_LinkedList *A, t_LinkedList *B, t_LinkedList *C)
{
	t_ListNode	tmp;

	if (!A || !B || !(B->headerNode.pRLink))
		return (EXIT_FAILURE);
	tmp.data = B->headerNode.pRLink->data;
	addLLElement(A, 0, tmp);
	removeLLElement(B, 0);
	tmp.data = PA;
	addLLElement(C, 0, tmp);
	return (EXIT_SUCCESS);
}

int	pb(t_LinkedList *A, t_LinkedList *B, t_LinkedList *C)
{
	t_ListNode	tmp;

	if (!A || !B || !(A->headerNode.pRLink))
		return (EXIT_FAILURE);
	tmp.data = A->headerNode.pRLink->data;
	addLLElement(B, 0, tmp);
	removeLLElement(A, 0);
	tmp.data = PB;
	addLLElement(C, 0, tmp);
	return (EXIT_SUCCESS);
}

int	sa(t_LinkedList *A, t_LinkedList *C)
{
	int			tmp;
	t_ListNode	command;

	if (A->currentElementCount == 0)
		return (EXIT_FAILURE);
	if (A->currentElementCount < 2)
		return (EXIT_SUCCESS);
	tmp = getLLElement(A, 0)->data;
	getLLElement(A, 0)->data = getLLElement(A, 1)->data;
	getLLElement(A, 1)->data = tmp;
	command.data = SA;
	addLLElement(C, 0, command);
	return (EXIT_SUCCESS);
}

int	sb(t_LinkedList *B, t_LinkedList *C)
{
	int			tmp;
	t_ListNode	command;

	if (B->currentElementCount == 0)
		return (EXIT_FAILURE);
	if (B->currentElementCount < 2)
		return (EXIT_SUCCESS);
	tmp = getLLElement(B, 0)->data;
	getLLElement(B, 0)->data = getLLElement(B, 1)->data;
	getLLElement(B, 1)->data = tmp;
	command.data = SB;
	addLLElement(C, 0, command);
	return (EXIT_SUCCESS);
}

int	ss(t_LinkedList *A, t_LinkedList *B, t_LinkedList *C)
{
	t_ListNode	command;

	if (sa(A, C) || sb(B, C))
		return (EXIT_FAILURE);
	command.data = SS;
	addLLElement(C, 0, command);
	return (EXIT_SUCCESS);
}
