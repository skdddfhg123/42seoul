/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woon <woon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 17:39:47 by chaewkim          #+#    #+#             */
/*   Updated: 2022/02/16 20:28:19 by woon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	s += len;
	while (len--)
	{
		if (*(char *)s-- == (char)c)
			return ((char *)++s);
	}
	if (*(char *)s == (char)c)
		return ((char *)s);
	return (0);
}
