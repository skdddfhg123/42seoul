/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmlee <dongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 22:28:08 by dongmlee          #+#    #+#             */
/*   Updated: 2021/05/10 22:58:36 by dongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*n_list;

	if (!(n_list = (t_list *)malloc(sizeof(t_list))))
		return (0);
	n_list->content = content;
	n_list->next = 0;
	return (n_list);
}
