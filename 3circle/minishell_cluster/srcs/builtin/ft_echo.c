/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmlee <dongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 19:35:46 by idongmin          #+#    #+#             */
/*   Updated: 2022/06/09 18:02:03 by dongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	check_option(char *str, int *opt)
{
	int	i;

	if (!(str[0] == '-' && str[1] == 'n'))
		return (FALSE);
	i = 2;
	while (str[i])
	{
		if (str[i] != 'n')
			return (FALSE);
		++i;
	}
	*opt = 1;
	return (TRUE);
}

static void	print_echo_argv(char **argv)
{
	while (*argv)
	{
		if (!(*(argv + 1)))
			ft_putstr_fd(*argv, 1);
		else
		{
			ft_putstr_fd(*argv, 1);
			ft_putstr_fd(" ", 1);
		}
		argv++;
	}
}

void	ft_echo(t_cmd *data, int pipe_flag)
{
	int		check_flag;
	int		opt_flag;
	char	**argv;

	argv = data->cmdlines;
	check_flag = 0;
	opt_flag = 0;
	argv++;
	while (*argv)
	{
		check_flag = check_option(*argv, &opt_flag);
		if (!check_flag)
			break ;
		argv++;
	}
	print_echo_argv(argv);
	if (!opt_flag)
		ft_putendl_fd("", 1);
	g_state.exit_status = 0;
	if (pipe_flag)
		exit(0);
}
