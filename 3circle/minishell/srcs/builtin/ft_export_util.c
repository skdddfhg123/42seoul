/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmlee <dongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 22:48:29 by woon              #+#    #+#             */
/*   Updated: 2022/06/09 17:42:02 by dongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	check_identifier2(char *str)
{
	if (!(ft_isalpha(*str) || *str == '_'))
		return (FALSE);
	while (*str)
	{
		if (!(ft_isalnum(*str) || *str == '_'))
			return (FALSE);
		str++;
	}
	return (TRUE);
}

int	get_equal_index(char *str)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
		{
			flag = 1;
			break ;
		}
		++i;
	}
	if (!flag)
		return (-1);
	return (i);
}

void	set_key_value(char *str, char **key, char **value, int index)
{
	int	i;
	int	len;

	i = -1;
	len = ft_strlen(str);
	if (index == -1)
		*key = new_key(str, len, &i);
	else
	{
		*key = new_key(str, index, &i);
		*value = new_value(str, len, index, &i);
	}
}

void	get_envp_change(char *key, char *value)
{
	t_list		*envpl;
	t_envp_list	*envp;
	int			exist_flag;

	exist_flag = 0;
	envpl = g_state.env;
	while (envpl)
	{
		envp = (t_envp_list *)(envpl)->content;
		if (!ft_strncmp((envp)->key, key, ft_strlen(key) + 1))
		{
			if (value)
			{
				free((envp)->value);
				(envp)->value = ft_strdup(value);
			}
			exist_flag = 1;
			break ;
		}
		(envpl) = (envpl)->next;
	}
	if (!exist_flag)
	{
		add_key_value(envpl, envp, key, value);
	}
}

int	modify_argv(char **argv)
{
	int		err_flag;
	int		index;
	char	*key;
	char	*value;

	err_flag = 0;
	while (*argv)
	{
		key = NULL;
		value = NULL;
		index = get_equal_index(*argv);
		set_key_value(*argv, &key, &value, index);
		if (!check_identifier2(key))
		{
			export_error(*argv);
			err_flag = 1;
		}
		else
			get_envp_change(key, value);
		free(key);
		free(value);
		argv++;
	}
	return (err_flag);
}
