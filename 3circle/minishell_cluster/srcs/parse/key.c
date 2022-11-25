/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woon <woon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 02:26:27 by woon              #+#    #+#             */
/*   Updated: 2022/06/05 05:39:56 by woon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*cmp_envp(char *key)
{
	int		i;
	int		len;
	char	*line;

	i = 0;
	line = ft_strjoin(key, "=");
	len = ft_strlen(line);
	while ((g_state.envp)[i])
	{
		if (!ft_strncmp(line, (g_state.envp)[i], len))
		{
			free(line);
			return ((g_state.envp)[i] + len);
		}
		i++;
	}
	free(line);
	return (0);
}

int	index_doub(char *s, char **ret)
{
	int		i;
	int		skip;
	int		len;
	char	*line;

	i = 0;
	*ret = ft_strdup("");
	len = -1;
	while (s[++len] != '\"')
	{
		if (s[len] == '$' && (ft_isalnum(s[len + 1]) || s[len + 1] == \
		'_' || s[len + 1] == '?'))
		{
			skip = find_key(s + len, &line);
			*ret = str_join(*ret, s, 0);
			*ret = str_join(*ret, line, 1);
			s += len + skip + 1;
			i += len + skip + 1;
			len = -1;
		}
	}
	s[len] = 0;
	i += len;
	*ret = str_join(*ret, s, 0);
	return (i + 1);
}

int	find_key(char *s, char **ret)
{
	int		i;
	char	*key;
	char	tmp;

	i = 0;
	*s = 0;
	s++;
	if (*s == '?')
	{
		*ret = ft_itoa(g_state.exit_status / 256);
		return (1);
	}
	while (ft_isalnum(s[i]) || s[i] == '_')
		i++;
	tmp = s[i];
	s[i] = 0;
	key = ft_strdup(s);
	s[i] = tmp;
	if (cmp_envp(key))
		*ret = ft_strdup(cmp_envp(key));
	else
		*ret = ft_strdup("");
	free(key);
	return (i);
}

void	change_key(char *s, int *len, t_redir *tmp, int *skip)
{
	char	*line;

	line = 0;
	*len += find_key(s + *len, &line) + 1;
	s[*len] = 0;
	tmp->file = str_join(tmp->file, s, 0);
	tmp->file = str_join(tmp->file, line, 1);
	s += *len + 1;
	*skip += *len;
	*len = -1;
}
