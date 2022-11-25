/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_heredoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woon <woon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 00:38:53 by woon              #+#    #+#             */
/*   Updated: 2022/06/09 00:54:35 by woon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static t_heredoc	*make_heredoc(t_redir *node)
{
	t_heredoc	*heredoc;

	heredoc = ft_calloc(1, sizeof(t_heredoc));
	heredoc->end_string = ft_strdup(node->next->file);
	heredoc->file_name = ft_strdup("./DMCW");
	heredoc->file_name = str_join(heredoc->file_name, \
	ft_itoa(node->next->index), 1);
	return (heredoc);
}

t_list	*create_list(void *data)
{
	t_list	*new;

	new = ft_calloc(sizeof(t_list), 1);
	new->content = data;
	return (new);
}

t_list	*get_heredoc(t_list *exec)
{
	t_list		*cur;
	t_list		*result;
	t_redir		*node;

	cur = exec->next;
	result = NULL;
	while (cur != NULL)
	{
		node = ((t_cmd *)cur->content)->root;
		while (node != NULL)
		{
			if (node->type == TYPE_HEREDOC)
				ft_lstadd_back(&result, create_list(make_heredoc(node)));
			node = node->left;
		}
		cur = cur->next;
	}
	return (result);
}
