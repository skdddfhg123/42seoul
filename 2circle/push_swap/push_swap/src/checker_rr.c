/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_rr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 03:36:19 by idongmin          #+#    #+#             */
/*   Updated: 2022/03/14 05:19:10 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	c_rra(t_LinkedList *A)
{
	t_ListNode	tmp;

	if (A->currentElementCount == 0)
		return (EXIT_FAILURE);
	if (A->currentElementCount == 1)
		return (EXIT_SUCCESS);
	tmp.data = getLLElement(A, A->currentElementCount - 1)->data;
	removeLLElement(A, A->currentElementCount - 1);
	addLLElement(A, 0, tmp);
	return (EXIT_SUCCESS);
}

int	c_rrb(t_LinkedList *B)
{
	t_ListNode	tmp;

	if (B->currentElementCount == 0)
		return (EXIT_FAILURE);
	if (B->currentElementCount == 1)
		return (EXIT_SUCCESS);
	tmp.data = getLLElement(B, B->currentElementCount - 1)->data;
	removeLLElement(B, B->currentElementCount - 1);
	addLLElement(B, 0, tmp);
	return (EXIT_SUCCESS);
}

int	c_rrr(t_LinkedList *A, t_LinkedList *B)
{
	if (c_rra(A) || c_rrb(B))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
