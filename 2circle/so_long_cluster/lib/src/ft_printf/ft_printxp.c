/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printxp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmlee <dongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:10:25 by idongmin          #+#    #+#             */
/*   Updated: 2022/04/05 14:41:11 by dongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	print_p2(unsigned long long p, char *base, int *len)
{
	if (p < 16)
	{
		write(1, &base[p % 16], 1);
		(*len)++;
	}
	else
	{
		print_p2(p / 16, base, len);
		print_p2(p % 16, base, len);
	}
}

int	print_p(const char **str, va_list ap)
{
	unsigned long long	p;
	int					len;

	len = 2;
	p = (unsigned long long)va_arg(ap, void *);
	if (!p)
	{
		write(1, "0x0", 3);
		(*str)++;
		return (3);
	}
	write(1, "0x", 2);
	(*str)++;
	print_p2(p, "0123456789abcdef", &len);
	return (len);
}

int	print_x(const char **str, va_list ap)
{
	unsigned int	p;
	int				len;

	len = 0;
	p = (unsigned int)va_arg(ap, unsigned int);
	(*str)++;
	print_p2(p, "0123456789abcdef", &len);
	return (len);
}

int	print_lx(const char **str, va_list ap)
{
	unsigned int	p;
	int				len;

	len = 0;
	p = (unsigned int)va_arg(ap, unsigned int);
	(*str)++;
	print_p2(p, "0123456789ABCDEF", &len);
	return (len);
}
