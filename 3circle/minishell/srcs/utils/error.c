/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaewkim <chaewkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 01:57:15 by woon              #+#    #+#             */
/*   Updated: 2022/06/09 17:42:23 by chaewkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	print_error(char *s)
{
	ft_putstr_fd("DMCW$ ", 2);
	ft_putendl_fd(s, 2);
}

void	print_malloc_error(void)
{
	print_error(MALLOC_ERROR);
	exit(1);
}
