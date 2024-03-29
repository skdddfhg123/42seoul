/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:11:32 by idongmin          #+#    #+#             */
/*   Updated: 2021/12/14 18:23:23 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		format_print(const char **str, va_list ap);
void	ft_putchar(char c);
int		ft_putchar_len(char c);
size_t	ft_strlen(const char *s);
int		print_c(const char **str, va_list ap);
int		print_s(const char **str, va_list ap);
void	print_d2(long long p, int *len);
int		print_di(const char **str, va_list ap);
int		print_u(const char **str, va_list ap);
void	print_p2(unsigned long long p, char *base, int *len);
int		print_p(const char **str, va_list ap);
int		print_x(const char **str, va_list ap);
int		print_X(const char **str, va_list ap);

#endif