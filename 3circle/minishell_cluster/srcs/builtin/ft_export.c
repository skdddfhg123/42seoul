/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmlee <dongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 18:52:03 by woon              #+#    #+#             */
/*   Updated: 2022/06/09 17:42:18 by dongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	export_error(char *argv)
{
	ft_putstr_fd("export: `", 2);
	ft_putstr_fd(argv, 2);
	ft_putendl_fd("': not a valid identifier", 2);
}

static void	print_export(char *key, char *value)
{
	ft_putstr_fd("declare -x ", 1);
	ft_putstr_fd(key, 1);
	if (value)
	{
		ft_putstr_fd("=\"", 1);
		ft_putstr_fd(value, 1);
		ft_putendl_fd("\"", 1);
	}
	else
		ft_putendl_fd("", 1);
}

static void	get_export(int pipe_flag)
{
	t_list		*envpl;
	t_envp_list	*envp;

	envpl = g_state.env;
	while (envpl)
	{
		envp = (t_envp_list *)envpl->content;
		print_export(envp->key, envp->value);
		envpl = envpl->next;
	}
	g_state.exit_status = 0;
	if (pipe_flag)
		exit(0);
}

void	ft_export(t_cmd *data, int pipe_flag)
{
	char	**argv;
	int		ret;

	ret = 0;
	argv = data->cmdlines;
	argv++;
	if (!*argv)
		get_export(pipe_flag);
	else
		ret = modify_argv(argv);
	g_state.exit_status = ret;
	if (pipe_flag)
		exit(ret);
}
