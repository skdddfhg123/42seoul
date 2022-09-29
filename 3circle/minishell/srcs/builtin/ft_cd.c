/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woon <woon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 21:43:49 by woon              #+#    #+#             */
/*   Updated: 2022/06/09 00:54:59 by woon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_option(char *str)
{
	if (!ft_strncmp(str, "-", 1) && ft_strlen(str) > 1 \
	&& ft_strncmp(str, "--", 3))
	{
		g_state.exit_status = 1;
		ft_putendl_fd("option T.T", 2);
		return (1);
	}
	return (0);
}

void	ft_cd(t_cmd *data, int pipe_flag)
{
	char	**argv;
	char	*now;

	g_state.exit_status = 0;
	now = getcwd(NULL, 256);
	argv = data->cmdlines;
	argv++;
	if (go_home_dir(*argv, now))
		;
	else if (check_option(*argv))
		;
	else if (!ft_strncmp(*argv, "-", 2))
		change_to_old_path(now);
	else if (!ft_strncmp(*argv, "~", 2) || !ft_strncmp(*argv, "~/", 3))
		use_tilde(*argv, now);
	else if (!chdir(*argv))
		change_values(now);
	else
		print_error_cd(*argv);
	free(now);
	if (pipe_flag)
		exit(g_state.exit_status);
}
