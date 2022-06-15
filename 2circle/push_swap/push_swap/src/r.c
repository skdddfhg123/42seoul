/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:47:31 by idongmin          #+#    #+#             */
/*   Updated: 2022/03/15 17:55:42 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	ra(t_LinkedList *A, t_LinkedList *C)
{
	t_ListNode	tmp;

	if (A->currentElementCount == 0)
		return (EXIT_FAILURE);
	if (A->currentElementCount == 1)
		return (EXIT_SUCCESS);
	tmp.data = getLLElement(A, 0)->data;
	removeLLElement(A, 0);
	addLLElement(A, A->currentElementCount, tmp);
	tmp.data = RA;
	addLLElement(C, 0, tmp);
	return (EXIT_SUCCESS);
}

int	rb(t_LinkedList *B, t_LinkedList *C)
{
	t_ListNode	tmp;

	if (B->currentElementCount == 0)
		return (EXIT_FAILURE);
	if (B->currentElementCount == 1)
		return (EXIT_SUCCESS);
	tmp.data = getLLElement(B, 0)->data;
	removeLLElement(B, 0);
	addLLElement(B, B->currentElementCount, tmp);
	tmp.data = RB;
	addLLElement(C, 0, tmp);
	return (EXIT_SUCCESS);
}

int	rr(t_LinkedList *A, t_LinkedList *B, t_LinkedList *C)
{
	t_ListNode	command;

	if (ra(A, C) || rb(B, C))
		return (EXIT_FAILURE);
	command.data = RR;
	addLLElement(C, 0, command);
	return (EXIT_SUCCESS);
}
