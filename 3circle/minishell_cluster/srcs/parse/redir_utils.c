/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woon <woon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 02:24:06 by woon              #+#    #+#             */
/*   Updated: 2022/06/05 02:25:19 by woon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	fill_struct(t_redir *tmp)
{
	char	**tmp_inputs;
	int		i;

	i = -1;
	tmp_inputs = (char **)malloc(sizeof(char *) * (tmp->index + 1));
	while (tmp->inputs[++i])
		tmp_inputs[i] = tmp->inputs[i];
	tmp_inputs[i] = tmp->file;
	tmp->file = 0;
	tmp_inputs[i + 1] = 0;
	free(tmp->inputs);
	tmp->inputs = tmp_inputs;
}
