/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woon <woon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 00:04:41 by chaewkim          #+#    #+#             */
/*   Updated: 2022/02/16 20:20:07 by woon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr(long num, int fd)
{
	if (num >= 10)
	{
		ft_putnbr(num / 10, fd);
		ft_putnbr(num % 10, fd);
	}
	else
	{
		num = num + '0';
		write(fd, &num, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long	num;

	num = n;
	if (num == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (num < 0)
	{
		num *= -1;
		write(fd, "-", 1);
	}
	ft_putnbr(num, fd);
}
