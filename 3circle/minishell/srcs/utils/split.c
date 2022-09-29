/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woon <woon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 00:50:57 by woon              #+#    #+#             */
/*   Updated: 2022/06/06 03:01:26 by woon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	cnt_word(char *s, char c)
{
	int		cnt;
	int		i;
	bool	quote[2];

	quote[0] = false;
	quote[1] = false;
	cnt = 0;
	i = 0;
	while (s[i])
	{
		if (c != s[i] && (i == 0 || c == s[i - 1]) && !quote[0] && !quote[1])
			cnt++;
		if (s[i] == '\'' && !quote[1])
			quote[0] = !quote[0];
		else if (s[i] == '\"' && !quote[0])
			quote[1] = !quote[1];
		i++;
	}
	if (quote[0] || quote[1])
		return (0);
	return (cnt);
}

static void	fill_word(int len, char **ret, char *s)
{
	char	*word;

	word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
		print_malloc_error();
	*ret = word;
	while (len)
		*word++ = *(s - len--);
	*word = 0;
}

static void	fill_array(char **ret, char *s, char c, int word_len)
{
	int		len;
	bool	quote[2];

	quote[0] = false;
	quote[1] = false;
	while (word_len--)
	{
		while (*s && c == *s)
			s++;
		len = 0;
		while (*s && (c != *s || quote[0] || quote[1]))
		{
			if (*s == '\'' && !quote[1])
				quote[0] = !quote[0];
			else if (*s == '\"' && !quote[0])
				quote[1] = !quote[1];
			s++;
			len++;
		}
		fill_word(len, ret, s);
		ret++;
	}
}

char	**split_func(char const *s, char c)
{
	char	**ret;
	int		word_len;
	int		i;

	word_len = cnt_word((char *)s, c);
	if (!word_len)
		return (0);
	ret = (char **)malloc((word_len + 1) * sizeof(char *));
	if (!ret)
		print_malloc_error();
	i = 0;
	while (i < word_len + 1)
		ret[i++] = 0;
	fill_array(ret, (char *)s, c, word_len);
	return (ret);
}
