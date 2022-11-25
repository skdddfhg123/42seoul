/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:16:51 by idongmin          #+#    #+#             */
/*   Updated: 2022/03/16 18:14:32 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int	print_c(const char **str, va_list ap)
{
	int	i;

	i = va_arg(ap, int);
	write(1, &i, 1);
	(*str)++;
	return (1);
}

int	print_s(const char **str, va_list ap)
{
	char	*s;

	s = va_arg(ap, char *);
	if (!s)
	{
		write(1, "(null)", 6);
		(*str)++;
		return (6);
	}
	write(1, s, ft_p_strlen(s));
	(*str)++;
	return (ft_p_strlen(s));
}
