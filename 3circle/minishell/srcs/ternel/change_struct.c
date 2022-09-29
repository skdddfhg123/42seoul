/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmlee <dongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:14:27 by woon              #+#    #+#             */
/*   Updated: 2022/06/09 19:18:26 by dongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	cmdline_num_check(t_cmd *tmp)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (tmp->cmdlines[++i])
	{
		if (!ft_strncmp(tmp->cmdlines[i], "<", 2))
			break ;
		else if (!ft_strncmp(tmp->cmdlines[i], "<<", 3))
			break ;
		else if (!ft_strncmp(tmp->cmdlines[i], ">", 2))
			break ;
		else if (!ft_strncmp(tmp->cmdlines[i], ">>", 3))
			break ;
		else
			j++;
	}
	return (j);
}

static int	break_case(char	*str)
{
	if (!ft_strncmp(str, "<", 2))
		return (1);
	else if (!ft_strncmp(str, "<<", 3))
		return (1);
	else if (!ft_strncmp(str, ">>", 3))
		return (1);
	else if (!ft_strncmp(str, ">", 2))
		return (1);
	return (0);
}

void	change_cmdlines(t_list *main_list)
{
	t_list	*tmp;
	char	**new_cmdlines;
	int		i;
	int		j;

	tmp = main_list->next;
	while (tmp)
	{
		i = -1;
		j = 0;
		new_cmdlines = (char **)malloc(sizeof(char *) * \
		(cmdline_num_check(((t_cmd *)tmp->content)) + 1));
		if (!new_cmdlines)
			print_malloc_error();
		while (((t_cmd *)tmp->content)->cmdlines[++i])
		{
			if (break_case(((t_cmd *)tmp->content)->cmdlines[i]))
				break ;
			else
				new_cmdlines[j++] = ft_strdup(((t_cmd *)tmp->content) \
				->cmdlines[i]);
		}
		after_case(new_cmdlines, j, &tmp);
	}
}

void	change_struct(t_list *main_list)
{
	change_node(main_list);
	change_cmdlines(main_list);
}
