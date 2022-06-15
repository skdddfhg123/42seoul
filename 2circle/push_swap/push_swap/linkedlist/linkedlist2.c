/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 22:35:06 by idongmin          #+#    #+#             */
/*   Updated: 2022/03/07 13:42:52 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"

void	clearLinkedList(t_LinkedList *pList)
{
	if (pList)
	{
		while (pList->currentElementCount > 0)
			removeLLElement(pList, pList->currentElementCount - 1);
	}
}

int	getLinkedListLength(t_LinkedList *pList)
{
	int	ret;

	ret = 0;
	if (pList)
		ret = pList->currentElementCount;
	return (ret);
}

void	deleteLinkedList(t_LinkedList *pList)
{
	if (pList)
	{
		clearLinkedList(pList);
		free(pList);
	}
}
