/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmlee <dongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 05:26:52 by idongmin          #+#    #+#             */
/*   Updated: 2022/06/09 17:46:06 by dongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	execve_error(char *str)
{
	ft_putstr_fd("bash: ", 2);
	ft_putstr_fd(str, 2);
	ft_putendl_fd(": command not found", 2);
	g_state.exit_status = 127;
	exit (127);
}

void	tree_traversal(t_redir *tree, t_cmd *data, \
int pipe_exist, t_list *heredoc)
{
	if (!tree)
	{
		dup2(254, 0);
		dup2(255, 1);
		close(254);
		close(255);
		return ;
	}
	if (tree->type == TYPE_IN_OVERWRITE)
		input(tree->next->file, 0);
	else if (tree->type == TYPE_OUT_OVERWRITE)
		output(tree->next->file, 1, 0);
	else if (tree->type == TYPE_HEREDOC)
		here_doc(1, 0, heredoc);
	else if (tree->type == TYPE_OUT_APPEND)
		output(tree->next->file, 1, 1);
	else if (tree->type == TYPE_CMD)
	{
		if (!pipe_exist)
			single_cmd(data);
		else
			multi_cmd(data);
	}
	tree_traversal(tree->left, data, pipe_exist, heredoc);
}
