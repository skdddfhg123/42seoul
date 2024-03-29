/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmlee <dongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 20:37:56 by dongmlee          #+#    #+#             */
/*   Updated: 2021/05/20 14:07:50 by dongmlee         ###   ########.fr       */
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
			return ((char *)&s[i]);
		i++;
	}
	if (data == '\0')
		return ((char *)&s[i]);
	return (0);
}
