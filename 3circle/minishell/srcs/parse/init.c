/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaewkim <chaewkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 01:57:16 by woon              #+#    #+#             */
/*   Updated: 2022/06/09 18:12:51 by chaewkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	init_redir(t_cmd *cmd)
{
	t_redir	*new;

	new = (t_redir *)malloc(sizeof(t_redir));
	cmd->dinput = new;
	if (!new)
		print_malloc_error();
	new->doub = false;
	new->next = 0;
	new->file = 0;
	new->index = 0;
	new->inputs = (char **)malloc(sizeof(char *));
	(new->inputs)[new->index] = 0;
}

t_redir	*redir(t_redir **list)
{
	t_redir	*tmp;
	t_redir	*cur;

	tmp = (t_redir *)malloc(sizeof(t_redir));
	if (!tmp)
		print_malloc_error();
	tmp->doub = false;
	tmp->next = 0;
	tmp->file = 0;
	tmp->inputs = 0;
	tmp->index = 0;
	cur = *list;
	if (!cur)
		*list = tmp;
	else
	{
		while (cur->next)
			cur = cur->next;
		cur->next = tmp;
	}
	return (tmp);
}

void	init_cmd(t_cmd *cmd, int i, char *s)
{
	if (!s)
		cmd->is_last = 0;
	else
		cmd->is_last = 1;
	if (i == 0)
		cmd->is_first = 0;
	else
		cmd->is_first = 1;
	cmd->cmdlines = 0;
	cmd->cmdline = 0;
	cmd->is_redir = 0;
	cmd->input = 0;
	cmd->output = 0;
	cmd->s_doub = 0;
	init_redir(cmd);
}
