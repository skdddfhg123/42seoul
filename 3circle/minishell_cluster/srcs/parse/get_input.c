/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaewkim <chaewkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 00:23:59 by woon              #+#    #+#             */
/*   Updated: 2022/06/09 18:18:36 by chaewkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_valid_quote(char *line)
{
	int		i;
	char	tmp;

	i = -1;
	tmp = 0;
	while (line[++i])
	{
		if (line[i] == '\'' || line[i] == '"')
		{
			if (tmp == 0)
				tmp = line[i];
			else if (tmp == '\'' && line[i] == '\'')
				tmp = 0;
			else if (tmp == '"' && line[i] == '"')
				tmp = 0;
			else if (tmp == '\'' && line[i] == '"')
				continue ;
			else if (tmp == '"' && line[i] == '\'')
				continue ;
		}
	}
	return (tmp == 0);
}

int	is_valid_space(char *line)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			cnt++;
		i++;
	}
	if (!ft_strlen(line) || cnt == (int)ft_strlen(line))
		return (0);
	return (1);
}

int	check_input(char *line)
{
	if (!line || !is_valid_quote(line) || !is_valid_space(line))
	{
		print_error("Invalid Input !");
		free(line);
		line = NULL;
		return (0);
	}
	return (1);
}

char	*read_line(char **line, t_list *main_list, t_list **heredoc)
{
	init_prompt(main_list, heredoc);
	*line = readline("DMCW$ ");
	return (*line);
}

void	get_input(void)
{
	char	*line;
	t_list	main_list;
	t_list	*heredoc;

	while (read_line(&line, &main_list, &heredoc))
	{
		if (line == NULL)
			break ;
		else if (*line != '\0')
		{
			if (check_input(line) && !check_pipe(line, &main_list))
			{
				parse_start(&main_list);
				heredoc = get_heredoc(&main_list);
				add_history(line);
				if (run_heredoc(heredoc))
				{
					init_signal();
					pipe_setting(main_list.next, heredoc);
				}
				unlink_all(heredoc);
			}
		}
		free(line);
	}
}
