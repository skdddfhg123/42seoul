/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 13:30:36 by idongmin          #+#    #+#             */
/*   Updated: 2022/02/17 00:31:55 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
클라이언트
함수 시작
1. arg 에러 체크
2. 메시지 길이 서버에 전송
3. 메시지 내용 서버에 전송
4. 종료

서버
함수 시작
1. pid 출력
- pid정보를 받아오고 함수 작성
2. 시그널 받을 준비 (while로 무한 루프)
3. 메시지 들어올 떄 체크하여 출력
- 메시지 출력하는 함수 작성 (비트마스킹 이용)
-- 메시지는 비트 단위로 받아서 8비트가 되면 char형태로 변환 (배열 이용??)
-- 
4. 프로그램 꺼질때까지 2,3 반복

알아야 할 것들
1. signal 함수 작동 방법
2. 비트마스킹 이용하여 문자열 출력
 
*/

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
			usleep(100);
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
	if (pid <= 100 || pid > 999999)
	{
		ft_printf("Pid is Wrong.\n");
		return (EXIT_FAILURE);
	}
	send_msg(pid, argv[2]);
}
