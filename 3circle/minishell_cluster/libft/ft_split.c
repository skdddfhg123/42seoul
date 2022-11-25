/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woon <woon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 03:07:55 by chaewkim          #+#    #+#             */
/*   Updated: 2022/02/16 20:30:49 by woon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_word_cnt(char *s, char c)
{
	size_t	i;
	size_t	word_cnt;

	word_cnt = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			word_cnt++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (word_cnt);
}

static char	*ft_rmall(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i++] = NULL;
	}
	return (NULL);
}

static char	*in_malloc(char const *word, char c, char **str)
{
	char	*tmp;
	size_t	i;

	i = 0;
	while (word[i] != c && word[i])
		i++;
	tmp = (char *)malloc(sizeof(char) * (i + 1));
	if (!tmp)
	{
		ft_rmall(str);
		return (NULL);
	}
	i = 0;
	while (word[i] != c && word[i])
	{
		tmp[i] = word[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

static char	**fill_malloc(char const *s, char **str, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			str[j] = in_malloc(&s[i], c, str);
			if (!(str[j++]))
			{
				free(str);
				str = NULL;
				return (NULL);
			}
			while (s[i] != c && s[i])
				i++;
		}
	}
	str[j] = 0;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	size_t	word_cnt;
	char	**str;

	if (!s)
		return (NULL);
	word_cnt = get_word_cnt((char *)s, c);
	str = (char **)malloc(sizeof(char *) * (word_cnt + 1));
	if (!str)
		return (NULL);
	str = fill_malloc(s, str, c);
	return (str);
}
