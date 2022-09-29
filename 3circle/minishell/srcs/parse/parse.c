/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaewkim <chaewkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 02:02:04 by woon              #+#    #+#             */
/*   Updated: 2022/06/09 18:13:23 by chaewkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	parse(t_cmd *cmd)
{
	char	**line;
	char	*tmp;
	int		i;

	tmp = ft_strdup(cmd->cmdline);
	if (is_valid_redir(cmd))
		return (1);
	cmd->cmdlines = split_func(tmp, ' ');
	free(cmd->cmdline);
	cmd->cmdline = ft_strdup(cmd->cmdlines[0]);
	line = cmd->cmdlines;
	i = 0;
	while (line[i])
	{
		line[i] = modify_line(line[i]);
		i++;
	}
	return (0);
}

void	parse_start(t_list *main_list)
{
	t_list	*cur_cmd;
	t_cmd	*cmd;

	cur_cmd = main_list->next;
	while (cur_cmd != NULL)
	{
		cmd = (t_cmd *)cur_cmd->content;
		if (parse(cmd))
		{
			print_error(NEWL_TOKEN_ERROR);
			g_state.exit_status = 258;
		}
		cur_cmd = cur_cmd->next;
	}
	change_struct(main_list);
}
