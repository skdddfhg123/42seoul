/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:59:16 by idongmin          #+#    #+#             */
/*   Updated: 2022/02/22 00:27:25 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"

t_LinkedList	*createLinkedList(void)
{
	t_LinkedList	*ret;

	ret = (t_LinkedList *)malloc(sizeof(t_LinkedList));
	if (!ret)
		return (0);
	if (ret)
	{
		memset(ret, 0, sizeof(t_LinkedList));
		ret->headerNode.pLLink = &(ret->headerNode);
		ret->headerNode.pRLink = &(ret->headerNode);
	}
	return (ret);
}

t_ListNode	*addNewNode(t_ListNode element)
{
	t_ListNode	*NewNode;

	NewNode = (t_ListNode *)malloc(sizeof(t_ListNode));
	if (!NewNode)
		return (NULL);
	*NewNode = element;
	NewNode->pLLink = NULL;
	NewNode->pRLink = NULL;
	return (NewNode);
}

int	addLLElement(t_LinkedList	*pList, int position, t_ListNode element)
{
	int			i;
	t_ListNode	*PreNode;
	t_ListNode	*NewNode;

	if (!pList)
		return (EXIT_FAILURE);
	if (position >= 0 && position <= pList->currentElementCount)
	{
		i = 0;
		NewNode = addNewNode(element);
		PreNode = &(pList->headerNode);
		while (i < position)
		{
			PreNode = PreNode->pRLink;
			i++;
		}
		NewNode->pLLink = PreNode;
		NewNode->pRLink = PreNode->pRLink;
		PreNode->pRLink = NewNode;
		NewNode->pRLink->pLLink = NewNode;
		pList->currentElementCount++;
	}
	return (EXIT_SUCCESS);
}

int	removeLLElement(t_LinkedList *pList, int position)
{
	int			i;
	int			arrayCount;
	t_ListNode	*pNode;
	t_ListNode	*DelNode;

	if (!pList)
		return (EXIT_FAILURE);
	arrayCount = getLinkedListLength(pList);
	if (position >= 0 && position < arrayCount)
	{
		i = 0;
		pNode = &(pList->headerNode);
		while (i < position)
		{
			pNode = pNode->pRLink;
			i++;
		}
		DelNode = pNode->pRLink;
		pNode->pRLink = DelNode->pRLink;
		DelNode->pRLink->pLLink = pNode;
		free(DelNode);
		pList->currentElementCount--;
	}
	return (EXIT_SUCCESS);
}

t_ListNode	*getLLElement(t_LinkedList *pList, int position)
{
	int			i;
	t_ListNode	*ret;
	t_ListNode	*pNode;

	ret = NULL;
	if (!pList)
		return (ret);
	if (position >= 0 && position < pList->currentElementCount)
	{
		i = 0;
		pNode = &(pList->headerNode);
		while (i <= position)
		{
			pNode = pNode->pRLink;
			i++;
		}
		ret = pNode;
	}
	return (ret);
}
