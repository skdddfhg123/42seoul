/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaewkim <chaewkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 02:20:40 by woon              #+#    #+#             */
/*   Updated: 2022/06/09 17:43:09 by chaewkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*str_join(char *s1, char *s2, int flag)
{
	char	*ret;
	int		len;
	int		i;

	len = 0;
	i = 0;
	ret = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!ret)
		print_malloc_error();
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	len = i;
	i = -1;
	while (s2[++i])
		ret[len + i] = s2[i];
	ret[len + i] = 0;
	free(s1);
	if (flag == 1)
		free(s2);
	return (ret);
}
