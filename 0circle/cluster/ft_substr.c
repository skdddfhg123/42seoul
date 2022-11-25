/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmlee <dongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 16:42:37 by dongmlee          #+#    #+#             */
/*   Updated: 2021/05/20 17:32:06 by dongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	s_size;
	size_t	i;
	size_t	real_len;

	if (!s)
		return (0);
	real_len = len;
	s_size = ft_strlen(s);
	if (start >= s_size)
		return (ft_strdup(""));
	if (len > s_size - (size_t)start)
		real_len = s_size - (size_t)start;
	if (!(res = ((char*)malloc(sizeof(char) * (real_len + 1)))))
		return (0);
	i = 0;
	while (real_len--)
		res[i++] = s[start++];
	res[i] = 0;
	return (res);
}
