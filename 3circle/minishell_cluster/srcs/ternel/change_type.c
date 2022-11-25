/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaewkim <chaewkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 21:31:51 by woon              #+#    #+#             */
/*   Updated: 2022/06/09 18:09:07 by chaewkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	change_type_in(t_cmd *cmd)
{
	int		i;
	t_redir	*tmp;
	t_redir	*pre;

	cmd->root = cmd->input;
	cmd->root->type = TYPE_IN_OVERWRITE;
	i = 0;
	tmp = cmd->root;
	pre = cmd->root;
	while (tmp)
	{
		if (i == 0)
			tmp->left = 0;
		else
		{
			tmp->left = pre;
			pre = pre->next;
		}
		i++;
		tmp = tmp->next;
	}
}

void	change_type_out(t_cmd *cmd)
{
	int		i;
	t_redir	*tmp;
	t_redir	*pre;

	cmd->root = cmd->output;
	if (cmd->root->doub)
		cmd->root->type = TYPE_OUT_OVERWRITE;
	else
		cmd->root->type = TYPE_OUT_APPEND;
	i = 0;
	tmp = cmd->root;
	pre = cmd->root;
	while (tmp)
	{
		if (i == 0)
			tmp->left = 0;
		else
		{
			tmp->left = pre;
			pre = pre->next;
		}
		i++;
		tmp = tmp->next;
	}
}

void	change_type_heredoc(t_cmd *cmd)
{
	cmd->root = cmd->dinput;
	cmd->root->type = TYPE_HEREDOC;
	cmd->root->left = 0;
	cmd->root->next = 0;
}

void	change_type_cmd(t_cmd *cmd)
{
	cmd->root = cmd->dinput;
	cmd->root->type = TYPE_CMD;
	cmd->root->left = 0;
	cmd->root->next = 0;
}

void	change_type_etc(t_cmd *cmd)
{
	cmd->root = cmd->dinput;
	cmd->root->type = TYPE_ETC;
	cmd->root->left = 0;
	cmd->root->next = 0;
}
