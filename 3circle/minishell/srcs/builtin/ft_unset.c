/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmlee <dongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 22:44:14 by woon              #+#    #+#             */
/*   Updated: 2022/06/09 17:42:30 by dongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "../../include/minishell.h"

void	free_list(t_list	*list)
{
	t_envp_list	*envp;

	envp = list->content;
	free(envp->key);
	free(envp->value);
	envp->key = NULL;
	envp->value = NULL;
	free(envp);
	envp = NULL;
	free(list);
	list = NULL;
}

static void	modify_list(t_list	*envpl, char *str)
{
	t_list		*prev;
	t_envp_list	*envp;

	prev = envpl;
	envpl = envpl->next;
	while (envpl)
	{
		envp = (t_envp_list *)envpl->content;
		if (!ft_strncmp(envp->key, str, ft_strlen(str) + 1))
		{
			prev->next = envpl->next;
			free_list(envpl);
			break ;
		}
		envpl = envpl->next;
		prev = prev->next;
	}
}

static void	get_key_rm(char *str)
{
	t_list		*envpl;
	t_envp_list	*envp;

	envpl = g_state.env;
	if (!envpl)
		return ;
	envp = (t_envp_list *)envpl->content;
	if (!ft_strncmp(envp->key, str, ft_strlen(str) + 1))
	{
		g_state.env = envpl->next;
		free_list(envpl);
		return ;
	}
	modify_list(envpl, str);
}

static int	check_identifier(char *str)
{
	if (!(ft_isalpha(*str) || *str == '_'))
		return (FALSE);
	str++;
	while (*str)
	{
		if (!(ft_isalnum(*str) || *str == '_'))
			return (FALSE);
		str++;
	}
	return (TRUE);
}

void	ft_unset(t_cmd	*data, int pipe_flag)
{
	char	**argv;

	argv = data->cmdlines;
	argv++;
	g_state.exit_status = 0;
	while (*argv)
	{
		if (!check_identifier(*argv))
		{
			ft_putstr_fd("unset: `", 2);
			ft_putstr_fd(*argv, 2);
			ft_putendl_fd("': not a valid identifier", 2);
			g_state.exit_status = 1;
		}
		else
			get_key_rm(*argv);
		argv++;
	}
	if (pipe_flag)
		exit(g_state.exit_status);
}
