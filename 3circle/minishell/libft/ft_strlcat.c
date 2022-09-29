/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaewkim <chaewkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 00:42:58 by chaewkim          #+#    #+#             */
/*   Updated: 2021/05/08 04:33:44 by chaewkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_dst;
	size_t	len_src;
	size_t	j;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	i = 0;
	j = len_dst;
	if (dstsize < len_dst)
		return (dstsize + len_src);
	else
	{
		while (src[i] && i + len_dst + 1 < dstsize)
		{
			dst[j++] = src[i++];
		}
		dst[j] = '\0';
		return (len_dst + len_src);
	}
}
