/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaewkim <chaewkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 00:28:54 by woon              #+#    #+#             */
/*   Updated: 2022/06/09 17:41:52 by chaewkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	get_paths(void)
{
	char	*path;
	char	**paths;
	int		i;

	path = get_env("PATH");
	paths = ft_split(path, ':');
	if (!paths)
		return ;
	i = 0;
	while (paths[i])
		i++;
	g_state.safe_paths = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		free(paths[i]);
		paths[i] = path;
		g_state.safe_paths[i] = paths[i];
		i++;
	}
	g_state.safe_paths[i] = NULL;
	free(paths);
}

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	copy_env(envp);
	get_paths();
	get_input();
	printf("exit\n");
	return (0);
}
