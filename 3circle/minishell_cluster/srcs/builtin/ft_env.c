/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmlee <dongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:50:36 by idongmin          #+#    #+#             */
/*   Updated: 2022/06/09 18:32:54 by dongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_env(t_cmd *data, int pipe_flag)
{
	t_list		*env;
	t_envp_list	*cur;

	(void)data;
	env = g_state.env;
	if (!env)
	{
		ft_putendl_fd("env must be one argv", 2);
		return ;
	}
	while (env)
	{
		cur = (t_envp_list *)env->content;
		ft_putstr_fd(cur->key, 1);
		write(1, "=", 1);
		ft_putendl_fd(cur->value, 1);
		env = env->next;
	}
	g_state.exit_status = 0;
	if (pipe_flag)
		exit(0);
}
