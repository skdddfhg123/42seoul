/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woon <woon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 21:43:49 by woon              #+#    #+#             */
/*   Updated: 2022/06/09 00:55:00 by woon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	change_global_oldpwd(char *prev)
{
	if (!g_state.oldpwd)
		g_state.oldpwd = ft_strdup(prev);
	else
	{
		free(g_state.oldpwd);
		g_state.oldpwd = ft_strdup(prev);
	}
}

void	change_envp_pwd(void)
{
	char	*path;
	int		i;

	i = 0;
	while (g_state.env_str[i])
	{
		if (!ft_strncmp(g_state.env_str[i], "PWD=", 5))
		{
			path = ft_strjoin("PWD=", g_state.pwd);
			free(g_state.env_str[i]);
			g_state.env_str[i] = ft_strdup(path);
			free(path);
			break ;
		}
		i++;
	}
}

void	change_envp_oldpwd(void)
{
	char	*path;
	int		i;

	i = 0;
	while (g_state.env_str[i])
	{
		if (!ft_strncmp(g_state.env_str[i], "OLDPWD=", 8))
		{
			path = ft_strjoin("OLDPWD=", g_state.oldpwd);
			free(g_state.env_str[i]);
			g_state.env_str[i] = ft_strdup(path);
			free(path);
			break ;
		}
		i++;
	}
}

void	change_values(char *now)
{
	change_global_oldpwd(now);
	change_envp_pwd();
	change_envp_oldpwd();
}

void	change_to_old_path(char *now)
{
	if (!g_state.oldpwd)
	{
		ft_putendl_fd("bash: cd: OLDPWD not set", 2);
		return ;
	}
	else
	{
		if (chdir(g_state.oldpwd))
		{
			ft_putstr_fd("bash: cd: ", 2);
			ft_putstr_fd(g_state.oldpwd, 2);
			ft_putendl_fd(": No such file or directory", 2);
			g_state.exit_status = 1;
			return ;
		}
		ft_putendl_fd(g_state.oldpwd, 1);
	}
	change_values(now);
}
