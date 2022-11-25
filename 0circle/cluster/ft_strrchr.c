/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmlee <dongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 21:22:07 by dongmlee          #+#    #+#             */
/*   Updated: 2021/05/20 14:16:06 by dongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	data;
	int				i;

	i = ft_strlen(s);
	data = (unsigned char)c;
	if (data == '\0')
		return ((char *)&s[i]);
	while (--i >= 0)
	{
		if (s[i] == data)
			return ((char *)&s[i]);
	}
	return (0);
}
