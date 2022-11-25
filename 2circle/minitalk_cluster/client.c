/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmlee <dongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 13:30:36 by dongmlee          #+#    #+#             */
/*   Updated: 2022/02/17 17:25:08 by dongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	kill_error(void)
{
	ft_printf("Kill error.\n");
	exit(1);
}

static void	send_msg(int pid, char *msg)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (1)
	{
		c = msg[i];
		j = -1;
		while (++j < 8)
		{
			if (c & (0x01 << j))
			{
				if (kill(pid, SIGUSR1) == -1)
					kill_error();
			}
			else if (kill(pid, SIGUSR2) == -1)
				kill_error();
			usleep(150);
		}
		if (!msg[i++])
			break ;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("Bad Argument.");
		return (EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	if (ft_isdigit(pid) || pid <= 100 || pid >= 99999)
	{
		ft_printf("Pid is Wrong.\n");
		return (EXIT_FAILURE);
	}
	send_msg(pid, argv[2]);
}
