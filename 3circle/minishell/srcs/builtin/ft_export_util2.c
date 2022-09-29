/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_util2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmlee <dongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 21:57:19 by woon              #+#    #+#             */
/*   Updated: 2022/06/09 17:42:11 by dongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_list	*init_list(void)
{
	t_list	*tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	if (!tmp)
		exit(1);
	tmp->content = NULL;
	tmp->next = NULL;
	return (tmp);
}

t_envp_list	*init_envp(char *key, char *value)
{
	t_envp_list	*tmp;

	tmp = (t_envp_list *)malloc(sizeof(t_envp_list));
	if (!tmp)
		exit(1);
	tmp->key = ft_strdup(key);
	tmp->value = ft_strdup(value);
	return (tmp);
}

char	*new_key(char *str, int len, int *i)
{
	char	*key;

	*i = -1;
	key = (char *)malloc(sizeof(char) * len + 1);
	while (++(*i) < len)
		key[*i] = str[*i];
	key[len] = 0;
	return (key);
}

char	*new_value(char *str, int len, int index, int *i)
{
	char	*value;
	int		j;

	j = -1;
	value = (char *)malloc(sizeof(char) * (len - index));
	if (!value)
		exit(1);
	++(*i);
	while (++j < len - index - 1)
		value[j] = str[*i + j];
	value[j] = 0;
	return (value);
}

void	add_key_value(t_list *envpl, t_envp_list *envp, char *key, char *value)
{
	t_list	*last;

	last = g_state.env;
	while ((last)->next)
		(last) = (last)->next;
	envpl = init_list();
	envp = init_envp(key, value);
	envpl->content = envp;
	last->next = envpl;
}
