/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ternel_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmlee <dongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 17:57:59 by chaewkim          #+#    #+#             */
/*   Updated: 2022/06/09 19:10:28 by dongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_redir	*create_node(t_list *main_list, char *s, int i)
{
	t_redir	*cur;

	(void)main_list;
	cur = (t_redir *)malloc(sizeof(t_redir));
	if (!cur)
		print_malloc_error();
	cur->file = s;
	cur->inputs = 0;
	cur->index = i;
	cur->doub = 0;
	if (i == 0)
		cur->type = TYPE_CMD;
	else if (!ft_strncmp(s, "<", 2))
		cur->type = TYPE_IN_OVERWRITE;
	else if (!ft_strncmp(s, "<<", 3))
		cur->type = TYPE_HEREDOC;
	else if (!ft_strncmp(s, ">", 2))
		cur->type = TYPE_OUT_OVERWRITE;
	else if (!ft_strncmp(s, ">>", 3))
		cur->type = TYPE_OUT_APPEND;
	else
		cur->type = TYPE_ETC;
	cur->left = 0;
	cur->next = 0;
	return (cur);
}

void	change_node(t_list *main_list)
{
	t_list	*tmp;
	t_redir	*cur;
	int		i;

	tmp = main_list->next;
	while (tmp)
	{
		i = 0;
		while (((t_cmd *)tmp->content)->cmdlines[i])
		{
			cur = create_node(main_list, \
			((t_cmd *)tmp->content)->cmdlines[i], i);
			if (i == 0)
				((t_cmd *)tmp->content)->root = cur;
			else
			{
				((t_cmd *)tmp->content)->root->next = cur;
				cur->left = ((t_cmd *)tmp->content)->root;
				((t_cmd *)tmp->content)->root = cur;
			}
			i++;
		}
		tmp = tmp->next;
	}
}

void	after_case(char **new_cmdlines, int j, t_list **tmp)
{
	new_cmdlines[j] = 0;
	((t_cmd *)(*tmp)->content)->cmdlines = new_cmdlines;
	*tmp = (*tmp)->next;
}
