/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaewkim <chaewkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 00:27:28 by woon              #+#    #+#             */
/*   Updated: 2022/06/09 18:10:47 by chaewkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	change_line(char *s, char **ret)
{
	int	i;

	i = 0;
	if (*s == '\'')
	{
		*s = 0;
		s++;
		while (s[i] != '\'')
			i++;
		s[i] = 0;
		*ret = ft_strdup(s);
		return (i + 1);
	}
	else if (*s == '$')
		return (find_key(s, ret));
	else if (*s == '\"')
	{
		*s = 0;
		s++;
		return (index_doub(s, ret));
	}
	return (0);
}

char	*modify_line(char *line)
{
	char	*tmp;
	char	*s;
	char	*ret;
	int		len;
	int		skip;

	s = line;
	tmp = ft_strdup("");
	len = -1;
	while (s[++len])
	{
		if ((s[len] == '$' && (ft_isalnum(s[len + 1]) || s[len + 1] == \
		'_' || s[len + 1] == '?')) || s[len] == '\'' || s[len] == '\"')
		{
			skip = change_line(s + len, &ret);
			tmp = str_join(tmp, s, 0);
			tmp = str_join(tmp, ret, 1);
			s += len + skip + 1;
			len = -1;
		}
	}
	tmp = str_join(tmp, s, 0);
	free(line);
	return (tmp);
}

int	fill_main_list(t_list *main_list, char **tmp_line)
{
	int		i;
	t_list	*tmp_node;
	t_cmd	*tmp_cmd;

	i = -1;
	while (tmp_line[++i])
	{
		tmp_cmd = (t_cmd *)malloc(sizeof(t_cmd));
		tmp_node = (t_list *)malloc(sizeof(t_list));
		if (!tmp_cmd || !tmp_node)
			print_malloc_error();
		init_cmd(tmp_cmd, i, tmp_line[i + 1]);
		tmp_cmd->cmdline = ft_strtrim(tmp_line[i], " ");
		if (!*(tmp_cmd->cmdline) && (tmp_cmd->is_last == 1 \
		|| tmp_cmd->is_first == 1))
		{
			print_error(PIPE_TOKEN_ERROR);
			return (1);
		}
		tmp_node->content = (char **)tmp_cmd;
		main_list->next = tmp_node;
		tmp_node->next = 0;
		main_list = tmp_node;
	}
	return (0);
}

int	check_pipe(char *line, t_list *main_list)
{
	char	**tmp_line;
	char	**del_node;
	int		ret;

	if (!line)
		return (1);
	tmp_line = split_func(line, '|');
	if (!tmp_line)
	{
		print_error(QUOTE_ERROR);
		return (1);
	}
	ret = fill_main_list(main_list, tmp_line);
	del_node = tmp_line;
	while (*del_node)
		free(*del_node++);
	free(tmp_line);
	return (ret);
}
