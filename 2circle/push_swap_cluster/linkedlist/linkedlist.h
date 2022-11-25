/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 22:00:49 by idongmin          #+#    #+#             */
/*   Updated: 2022/03/07 13:42:47 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKEDLIST_H
# define LINKEDLIST_H

# include <stdlib.h>
# include <string.h>

typedef struct s_ListNode
{
	long long			data;
	struct s_ListNode	*pLLink;
	struct s_ListNode	*pRLink;
}						t_ListNode;

typedef struct s_LinkedList
{
	int			currentElementCount;
	t_ListNode	headerNode;
}				t_LinkedList;

t_LinkedList	*createLinkedList(void);
t_ListNode		*addNewNode(t_ListNode element);
int				addLLElement(t_LinkedList *pList, int position, \
t_ListNode element);
int				removeLLElement(t_LinkedList *pList, int position);
t_ListNode		*getLLElement(t_LinkedList *pList, int position);
void			clearLinkedList(t_LinkedList *pList);
int				getLinkedListLength(t_LinkedList *pList);
void			deleteLinkedList(t_LinkedList *pList);
void			displayLinkedList(t_LinkedList *pList);

# define TRUE		1
# define FALSE		0

#endif