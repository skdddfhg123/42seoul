/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmlee <dongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 04:58:07 by dongmlee          #+#    #+#             */
/*   Updated: 2022/06/09 18:31:57 by dongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	cmd_setting(t_cmd *cmds, int *i, char **cmd_path)
{
	cmds->cmdline = ft_strtrim(*cmds->cmdlines, " ");
	*i = -1;
	*cmd_path = NULL;
}

char	*get_val_cmd(t_cmd *cmds)
{
	char		*cmd_path;
	int			i;
	struct stat	buf;

	if (stat(cmds->cmdline, &buf) == 0)
	{
		if ((buf.st_mode & S_IFMT) == S_IFDIR)
			return (NULL);
		return (cmds->cmdline);
	}
	else
	{
		cmd_setting(cmds, &i, &cmd_path);
		while (g_state.safe_paths[++i])
		{
			cmd_path = ft_strjoin(g_state.safe_paths[i], cmds->cmdline);
			if (stat(cmd_path, &buf) == 0)
				return (cmd_path);
			free(cmd_path);
			cmd_path = NULL;
		}
	}
	return (NULL);
}

void	execute_cmd(t_cmd *cmds)
{
	char	*path;
	int		pid;

	pid = fork();
	if (pid < 0)
		exit(1);
	else if (pid == 0)
	{
		path = get_val_cmd(cmds);
		if (execve(path, cmds->cmdlines, g_state.envp))
			execve_error(cmds->cmdline);
	}
	else
	{
		wait(NULL);
		g_state.exit_status = WEXITSTATUS(g_state.exit_status);
		if (g_state.signal)
			g_state.exit_status = g_state.signal;
	}
}

void	single_cmd(t_cmd *cmds)
{
	if (!ft_strncmp("pwd", cmds->cmdline, 4))
		ft_pwd(cmds, 0);
	else if (!ft_strncmp("exit", cmds->cmdline, 5))
		ft_exit(cmds, 0);
	else if (!ft_strncmp("echo", cmds->cmdline, 5))
		ft_echo(cmds, 0);
	else if (!ft_strncmp("env", cmds->cmdline, 4))
		ft_env(cmds, 0);
	else if (!ft_strncmp("unset", cmds->cmdline, 6))
		ft_unset(cmds, 0);
	else if (!ft_strncmp("export", cmds->cmdline, 6))
		ft_export(cmds, 0);
	else if (!ft_strncmp("cd", cmds->cmdline, 3))
		ft_cd(cmds, 0);
	else
		execute_cmd(cmds);
}

void	multi_cmd(t_cmd *cmds)
{
	if (!ft_strncmp("pwd", cmds->cmdline, 4))
		ft_pwd(cmds, 1);
	else if (!ft_strncmp("exit", cmds->cmdline, 5))
		ft_exit(cmds, 1);
	else if (!ft_strncmp("echo", cmds->cmdline, 5))
		ft_echo(cmds, 1);
	else if (!ft_strncmp("env", cmds->cmdline, 4))
		ft_env(cmds, 1);
	else if (!ft_strncmp("unset", cmds->cmdline, 6))
		ft_unset(cmds, 1);
	else if (!ft_strncmp("export", cmds->cmdline, 6))
		ft_export(cmds, 1);
	else if (!ft_strncmp("cd", cmds->cmdline, 3))
		ft_cd(cmds, 1);
	else
	{
		cmds->path = get_val_cmd(cmds);
		if (execve(cmds->path, cmds->cmdlines, g_state.envp))
			execve_error(cmds->cmdline);
	}
}
