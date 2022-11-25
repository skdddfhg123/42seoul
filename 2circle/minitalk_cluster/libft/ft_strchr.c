/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmlee <dongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 20:37:56 by dongmlee          #+#    #+#             */
/*   Updated: 2022/02/17 16:07:45 by dongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	data;
	int				i;

	i = 0;
	data = (unsigned char)c;
	while (s[i])
	{
		if (s[i] == data)
		{
			return ((char *)&s[i]);
		}
		i++;
		if (s[i] == data && data == '\0')
			return ((char *)&s[i]);
	}
	if (data == '\0')
		return ((char *)&s[i]);
	return (0);
}
