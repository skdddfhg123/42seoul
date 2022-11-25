/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:43:49 by idongmin          #+#    #+#             */
/*   Updated: 2022/03/14 05:02:31 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	c_pa(t_LinkedList *A, t_LinkedList *B)
{
	t_ListNode	tmp;

	if (!A || !B || !(B->headerNode.pRLink))
		return (EXIT_FAILURE);
	tmp.data = B->headerNode.pRLink->data;
	addLLElement(A, 0, tmp);
	removeLLElement(B, 0);
	return (EXIT_SUCCESS);
}

int	c_pb(t_LinkedList *A, t_LinkedList *B)
{
	t_ListNode	tmp;

	if (!A || !B || !(A->headerNode.pRLink))
		return (EXIT_FAILURE);
	tmp.data = A->headerNode.pRLink->data;
	addLLElement(B, 0, tmp);
	removeLLElement(A, 0);
	return (EXIT_SUCCESS);
}

int	c_sa(t_LinkedList *A)
{
	int	tmp;

	if (!A)
		return (EXIT_FAILURE);
	if (A->currentElementCount < 2)
		return (EXIT_SUCCESS);
	tmp = getLLElement(A, 0)->data;
	getLLElement(A, 0)->data = getLLElement(A, 1)->data;
	getLLElement(A, 1)->data = tmp;
	return (EXIT_SUCCESS);
}

int	c_sb(t_LinkedList *B)
{
	int	tmp;

	if (!B)
		return (EXIT_FAILURE);
	if (B->currentElementCount < 2)
		return (EXIT_SUCCESS);
	tmp = getLLElement(B, 0)->data;
	getLLElement(B, 0)->data = getLLElement(B, 1)->data;
	getLLElement(B, 1)->data = tmp;
	return (EXIT_SUCCESS);
}

int	c_ss(t_LinkedList *A, t_LinkedList *B)
{
	if (c_sa(A) || c_sb(B))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
