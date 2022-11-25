/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_envp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaewkim <chaewkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 02:01:00 by woon              #+#    #+#             */
/*   Updated: 2022/06/09 18:14:03 by chaewkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static	void	add_envpl(t_list **result, char *env_str)
{
	t_envp_list	*envpl;
	char		**split_env;

	envpl = (t_envp_list *)malloc(sizeof(t_envp_list));
	split_env = (char **)malloc(sizeof(char *) * 3);
	if (!envpl || !split_env)
		print_malloc_error();
	split_env = ft_split(env_str, '=');
	envpl->key = ft_strdup(split_env[0]);
	envpl->value = ft_strdup(split_env[1]);
	ft_lstadd_back(result, create_list(envpl));
	free(split_env);
}

void	copy_env(char **envp)
{
	int		i;
	t_list	*result;

	result = NULL;
	if (*envp != NULL)
	{
		g_state.envp = envp;
		i = -1;
		while (envp[++i])
			i++;
		g_state.env_str = (char **)malloc(sizeof(char *) * (i + 1));
		i = -1;
		while (envp[++i])
		{
			g_state.env_str[i] = ft_strdup(envp[i]);
			add_envpl(&result, g_state.env_str[i]);
		}
		g_state.env_str[i] = NULL;
		g_state.env = result;
		g_state.pwd = get_env("PWD");
		g_state.oldpwd = get_env("OLDPWD");
	}
	return ;
}

char	*get_env(char *key)
{
	int		i;

	if (ft_strlen(key) == 0)
		return (ft_strdup(""));
	i = -1;
	while (g_state.env_str[++i])
	{
		if (!ft_strncmp(g_state.env_str[i], key, ft_strlen(key)))
			return (ft_substr(g_state.env_str[i], ft_strlen(key) + 1, \
			ft_strlen(g_state.env_str[i]) - ft_strlen(key) + 1));
	}
	return (ft_strdup(""));
}
