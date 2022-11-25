/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woon <woon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 02:15:46 by woon              #+#    #+#             */
/*   Updated: 2022/06/05 02:31:12 by woon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	index_file(char *s, t_redir *tmp)
{
	int		skip;
	int		len;
	char	c;

	skip = 0;
	len = 0;
	while (*(++s) == ' ')
		skip++;
	if (*s == 0)
		return (-3);
	tmp->file = ft_strdup("");
	while (!(s[len] == ' ' || s[len] == 0))
	{
		if (s[len] == '$' && (ft_isalnum(s[len + 1]) || \
		s[len + 1] == '_' || s[len + 1] == '?'))
			change_key(s, &len, tmp, &skip);
		len++;
	}
	skip += len;
	c = s[len];
	s[len] = 0;
	tmp->file = str_join(tmp->file, s, 0);
	s[len] = c;
	return (skip);
}

int	index_file_doub(char *s, t_redir *tmp)
{
	int		skip;
	int		len;
	char	c;

	skip = 0;
	len = 0;
	while (*(++s) == ' ')
		skip++;
	if (*s == 0)
		return (-3);
	tmp->file = ft_strdup("");
	while (!(s[len] == ' ' || s[len] == 0))
		len++;
	skip += len;
	c = s[len];
	s[len] = 0;
	tmp->file = str_join(tmp->file, s, 0);
	s[len] = c;
	tmp->index += 1;
	fill_struct(tmp);
	return (skip);
}
