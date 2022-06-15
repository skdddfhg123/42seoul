/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:12:24 by idongmin          #+#    #+#             */
/*   Updated: 2022/02/16 23:47:01 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
서버
함수 시작
1. pid 출력
- pid정보를 받아오고 함수 작성 (완)
2. 시그널 받을 준비 (while로 무한 루프) (완)
3. 메시지 들어올 떄 체크하여 출력
- 메시지 출력하는 함수 작성 (비트마스킹 이용)
-- SIGUSR1, SIGUSR2를 이용해 0이 들어오면 SIGUSR1을 실행 , 1이 들어오면 SIGUSR2을 실행시킨다.
-- 이렇게 8비트가 들어오게 되면 그것을 배열에 묶어서 char형태로 변환해준다
-- (주의: 문자는 뒤에 널문자가 함께 들어온다.)
-- 메시지는 비트 단위로 받아서 8비트가 되면 char형태로 변환 (배열 이용??)
4. 프로그램 꺼질때까지 2,3 반복
*/

#include "minitalk.h"

void	initialization(void)
{
	ft_memset(g_struct.sum, 0 , BUFFSIZE);
	g_struct.i = 0;
	g_struct.len = 0;
	g_struct.cha = 0;
}

void	recieve(int sig)
{
	if (sig == SIGUSR1)
		g_struct.cha |= (1 << g_struct.i);
	g_struct.i++;
	if (g_struct.i == 8)
	{
		g_struct.sum[g_struct.len] = g_struct.cha;
		g_struct.i = 0;
		g_struct.cha = 0;
		if (!g_struct.sum[g_struct.len++] || g_struct.len == 1023)
		{
			write(1, g_struct.sum, g_struct.len);
			write(1, "\n", 1);
			ft_bzero(g_struct.sum, BUFFSIZE);
			g_struct.len = 0;
			usleep(200);
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
