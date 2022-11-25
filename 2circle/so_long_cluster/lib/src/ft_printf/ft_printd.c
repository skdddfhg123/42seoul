/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:15:54 by idongmin          #+#    #+#             */
/*   Updated: 2022/03/16 18:14:47 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	print_d2(long long p, int *len)
{
	long long	n;

	n = p;
	if (n > 9)
	{
		(*len)++;
		print_d2(n / 10, len);
		ft_p_putchar((n % 10) + '0');
	}
	else
	{
		(*len)++;
		ft_p_putchar(n + '0');
	}
}

int	print_di(const char **str, va_list ap)
{
	long long	n;
	int			len;

	len = 0;
	n = (long long)va_arg(ap, int);
	if (n < 0)
	{
		ft_p_putchar('-');
		n = -n;
		len++;
	}
	print_d2(n, &len);
	(*str)++;
	return (len);
}

int	print_u(const char **str, va_list ap)
{
	long long	n;
	int			len;

	len = 0;
	n = (long long)va_arg(ap, unsigned int);
	print_d2(n, &len);
	(*str)++;
	return (len);
}
