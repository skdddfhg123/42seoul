/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 03:35:49 by idongmin          #+#    #+#             */
/*   Updated: 2022/03/14 05:18:58 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	c_ra(t_LinkedList *A)
{
	t_ListNode	tmp;

	if (A->currentElementCount == 0)
		return (EXIT_FAILURE);
	if (A->currentElementCount == 1)
		return (EXIT_SUCCESS);
	tmp.data = getLLElement(A, 0)->data;
	removeLLElement(A, 0);
	addLLElement(A, A->currentElementCount, tmp);
	return (EXIT_SUCCESS);
}

int	c_rb(t_LinkedList *B)
{
	t_ListNode	tmp;

	if (B->currentElementCount == 0)
		return (EXIT_FAILURE);
	if (B->currentElementCount == 1)
		return (EXIT_SUCCESS);
	tmp.data = getLLElement(B, 0)->data;
	removeLLElement(B, 0);
	addLLElement(B, B->currentElementCount, tmp);
	return (EXIT_SUCCESS);
}

int	c_rr(t_LinkedList *A, t_LinkedList *B)
{
	if (c_ra(A) || c_rb(B))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
