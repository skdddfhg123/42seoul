/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woon <woon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 05:26:05 by chaewkim          #+#    #+#             */
/*   Updated: 2022/02/16 20:12:44 by woon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}
