/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:38:11 by idongmin          #+#    #+#             */
/*   Updated: 2021/12/14 18:27:21 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_print(const char **str, va_list ap)
{
	while (**str)
	{
		if ((char) **str == 'c')
			return (print_c(str, ap));
		else if ((char) **str == 's')
			return (print_s(str, ap));
		else if ((char) **str == 'p')
			return (print_p(str, ap));
		else if ((char) **str == 'd' || **str == 'i')
			return (print_di(str, ap));
		else if ((char) **str == 'u')
			return (print_u(str, ap));
		else if ((char) **str == 'x')
			return (print_x(str, ap));
		else if ((char) **str == 'X')
			return (print_X(str, ap));
		else if ((char) **str == '%')
		{
			(*str)++;
			return (ft_putchar_len('%'));
		}
		else
			return (0);
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	va_list	ap;

	va_start(ap, str);
	len = 0;
	while (*str)
	{
		while (*str && str[0] != '%')
		{
			len += ft_putchar_len(str[0]);
			str++;
		}
		if (*str == '%')
		{
			str++;
			len += format_print(&str, ap);
		}
	}
	va_end(ap);
	return (len);
}
