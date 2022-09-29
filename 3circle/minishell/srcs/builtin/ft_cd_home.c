/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_home.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmlee <dongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 21:43:49 by woon              #+#    #+#             */
/*   Updated: 2022/06/09 17:41:14 by dongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	use_tilde(char *str, char *now)
{
	const char	*tilde = "/Users/woon";
	int			len;
	char		*path;

	len = ft_strlen(str) + ft_strlen((char *)tilde);
	path = malloc(sizeof(char) * len);
	if (!path)
		exit(1);
	if (*str == '~')
	{
		str++;
		if (*str == '/')
			str++;
	}
	path = ft_strjoin(tilde, str);
	if (chdir(path))
	{
		free(g_state.pwd);
		g_state.pwd = strdup(path);
		g_state.exit_status = 1;
	}
	else
		change_values(now);
	ft_free((void **)&path);
}

static char	*find_home(int *flag)
{
	char	*path;
	char	**envp;
	int		i;

	*flag = 0;
	path = NULL;
	envp = g_state.envp;
	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "HOME=", 6))
		{
			printf("asdf\n");
			path = (ft_split(envp[i], '='))[1];
			printf("path = %s\n", path);
			*flag = 1;
			break ;
		}
		i++;
	}
	return (path);
}

static void	use_home_val(char *now)
{
	int		flag;
	char	*path;

	path = find_home(&flag);
	if (!flag)
	{
		ft_putendl_fd("bash: cd: HOME not set", 2);
		g_state.exit_status = 1;
		return ;
	}
	if (path == NULL || !ft_strncmp(path, "", 2))
	{
		free(g_state.pwd);
		g_state.pwd = ft_strdup(path);
		chdir(path);
	}
	else
	{
		if (chdir(path) == -1)
			print_error_cd(path);
		else
			change_values(now);
	}
}

int	go_home_dir(char *argv, char *now)
{
	if (!argv || !ft_strncmp("--", argv, 3))
	{
		use_home_val(now);
		return (TRUE);
	}
	return (FALSE);
}
