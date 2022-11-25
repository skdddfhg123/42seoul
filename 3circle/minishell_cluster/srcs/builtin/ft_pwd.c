/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woon <woon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 21:30:30 by idongmin          #+#    #+#             */
/*   Updated: 2022/06/08 23:12:02 by woon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	check_option(char *str)
{
	if (ft_strncmp(str, "--", 3) && str[0] == '-' && ft_strlen(str) > 1)
		return (TRUE);
	else
		return (FALSE);
}

void	ft_pwd(t_cmd *data, int pipe_flag)
{
	char	*now_path;
	char	**argv;

	argv = data->cmdlines;
	argv++;
	if (*argv && check_option(*argv))
	{
		ft_putendl_fd("Options do not work.", 2);
		return ;
	}
	now_path = NULL;
	now_path = getcwd(NULL, 256);
	if (now_path == NULL)
	{
		ft_putendl_fd("fail getcwd()", 2);
		exit(1);
	}
	ft_putendl_fd(now_path, 1);
	free(g_state.pwd);
	g_state.pwd = ft_strdup(now_path);
	g_state.exit_status = 0;
	free(now_path);
	if (pipe_flag)
		exit(0);
}
