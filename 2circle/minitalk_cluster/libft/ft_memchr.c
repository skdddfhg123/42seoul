/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmlee <dongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 16:48:25 by dongmlee          #+#    #+#             */
/*   Updated: 2022/02/17 16:07:55 by dongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	data;
	unsigned char	*s_ptr;

	i = 0;
	data = (unsigned char)c;
	s_ptr = (unsigned char *)s;
	while (i < n)
	{
		if (s_ptr[i] == data)
		{
			return (&s_ptr[i]);
		}
		i++;
	}
	return (0);
}
