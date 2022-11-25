/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmlee <dongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:12:24 by dongmlee          #+#    #+#             */
/*   Updated: 2022/02/17 17:02:26 by dongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	initialization(void)
{
	ft_memset(g_struct.sum, 0, BUFFSIZE);
	g_struct.i = 0;
	g_struct.len = 0;
}

void	recieve(int sig)
{
	if (sig == SIGUSR1)
		g_struct.sum[g_struct.len] |= (1 << g_struct.i);
	g_struct.i++;
	if (g_struct.i == 8)
	{
		g_struct.i = 0;
		if (g_struct.len == 1023 || !g_struct.sum[g_struct.len++])
		{
			write(1, g_struct.sum, g_struct.len + 1);
			write(1, "\n", 1);
			ft_bzero(g_struct.sum, BUFFSIZE);
			g_struct.len = 0;
			usleep(100);
		}
	}
}

int	main(void)
{
	ft_printf("PID : %d\n", getpid());
	initialization();
	if (signal(SIGUSR1, recieve) == SIG_ERR)
	{
		write(1, "Sending error.\n", 15);
		exit(1);
	}
	if (signal(SIGUSR2, recieve) == SIG_ERR)
	{
		write(1, "Sending error.\n", 15);
		exit(1);
	}
	while (1)
	{
		pause();
	}
	return (0);
}
