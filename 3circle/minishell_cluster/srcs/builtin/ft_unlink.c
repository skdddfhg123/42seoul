/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unlink.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woon <woon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 19:16:38 by woon              #+#    #+#             */
/*   Updated: 2022/06/08 18:40:32 by woon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	unlink_all(t_list *heredoc)
{
	t_list		*iter;
	t_heredoc	*data;
	int			fd;

	iter = heredoc;
	while (iter)
	{
		data = iter->content;
		fd = open(data->file_name, O_RDONLY, 0644);
		if (unlink(data->file_name) && fd != -1)
			exit(1);
		iter = iter->next;
	}
}
