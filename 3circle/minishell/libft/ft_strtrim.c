/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woon <woon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 22:53:10 by chaewkim          #+#    #+#             */
/*   Updated: 2022/02/16 20:33:48 by woon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	is_sep(char const s1, char const *set)
{
	size_t		i;

	i = 0;
	while (set[i])
	{
		if (s1 == set[i++])
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*str;
	size_t		left;
	size_t		right;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	left = 0;
	right = ft_strlen(s1);
	while (left < right && is_sep(s1[left], set))
		left++;
	while (left < right && is_sep(s1[right - 1], set))
		right--;
	str = (char *)malloc(sizeof(char) * (right - left + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, &s1[left], right - left + 1);
	return (str);
}
