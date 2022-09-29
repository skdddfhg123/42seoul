/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmlee <dongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 10:39:12 by dongmlee          #+#    #+#             */
/*   Updated: 2021/06/09 19:36:39 by dongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_digits(long long n)
{
	size_t			len;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	else if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static long long	ft_neg_check(long long n)
{
	long long		tmp;

	tmp = 0;
	if (n < 0)
	{
		tmp = n * -1;
	}
	else
		tmp = n;
	return (tmp);
}

char				*ft_itoa(int n)
{
	char			*str;
	long long		tmp;
	size_t			len;

	if (!(tmp = ft_neg_check((long long)n)))
		return (ft_strdup("0"));
	len = ft_digits((long long)n);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	if (n < 0)
		str[0] = '-';
	str[len] = 0;
	while (tmp > 0)
	{
		str[--len] = (tmp % 10) + '0';
		tmp /= 10;
	}
	return (str);
}
