/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmlee <dongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 21:43:49 by woon              #+#    #+#             */
/*   Updated: 2022/06/09 17:41:51 by dongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

#define MANYARGU 0
#define NUMBER 1

static void	print_exit_error(char *str, int type, int pipe_flag)
{
	ft_putstr_fd("bash: ", 2);
	ft_putstr_fd("exit: ", 2);
	if (type == MANYARGU)
	{
		ft_putendl_fd("too many arguments exit", 2);
		if (pipe_flag)
			exit(1);
	}
	else if (type == NUMBER)
	{
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd("numeric argument required", 2);
		exit(255);
	}
}

static int	check_all_integer(char *str)
{
	if (*str == '+' || *str == '-')
		++str;
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		++str;
	}
	return (1);
}

static void	ft_exit_execute(char **argv, int pipe_flag)
{
	int	ret;

	if (check_all_integer(*argv))
	{
		ret = ft_atoi(*argv);
		if (!pipe_flag)
			ft_putendl_fd("exit", 1);
		argv++;
		if (*argv)
			print_exit_error("", 0, pipe_flag);
		else
			exit(ret);
	}
	else
		print_exit_error(*argv, 1, pipe_flag);
}

void	ft_exit(t_cmd *data, int pipe_flag)
{
	char	**argv;

	argv = data->cmdlines;
	argv++;
	if (*argv == NULL)
	{
		if (!pipe_flag)
			exit(0);
	}
	else
		ft_exit_execute(argv, pipe_flag);
}
