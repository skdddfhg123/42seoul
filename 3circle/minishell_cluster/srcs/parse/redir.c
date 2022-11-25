/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woon <woon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 02:07:47 by woon              #+#    #+#             */
/*   Updated: 2022/06/06 02:45:00 by woon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_cmdline(char *s)
{
	int	len;

	len = 0;
	while ((s[len] != 0) && (s[len] != '>') \
	&& (s[len] != '<'))
	{
		if (s[len] == '\'')
		{
			while (s[len + 1] != '\'')
				len++;
			len++;
		}
		if (s[len] == '\"')
		{
			while (s[len + 1] != '\"')
				len++;
			len++;
		}
		len++;
	}
	return (len);
}

int	index_redir(char *s, t_cmd *cmd)
{
	t_redir	*tmp;

	if (*s == '>')
	{
		tmp = redir(&(cmd->output));
		if (*(s + 1) == '>')
			tmp->doub = true;
	}
	else
	{
		cmd->s_doub = 0;
		if (*(s + 1) == '<')
		{
			*s = 0;
			cmd->s_doub = 1;
			return (index_file_doub(s + 1, cmd->dinput) + 1);
		}
		else
			tmp = redir(&(cmd->input));
	}
	*s = 0;
	if (tmp->doub)
		return (index_file(s + 1, tmp) + 1);
	return (index_file(s, tmp));
}

int	is_valid_redir(t_cmd *cmd)
{
	char	*tmp;
	char	*s;
	int		len;
	int		skip;

	s = cmd->cmdline;
	tmp = ft_strdup("");
	len = check_cmdline(s);
	while (s[len] == '<' || s[len] == '>')
	{
		cmd->is_redir = 1;
		skip = index_redir(s + len, cmd);
		if (skip < 0)
		{
			free(tmp);
			return (1);
		}
		tmp = str_join(tmp, s, 0);
		s += len + skip + 1;
		len = check_cmdline(s);
	}
	tmp = str_join(tmp, s, 0);
	free(cmd->cmdline);
	cmd->cmdline = tmp;
	return (0);
}
