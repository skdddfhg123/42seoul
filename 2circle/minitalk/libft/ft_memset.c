/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 12:40:26 by dongmlee          #+#    #+#             */
/*   Updated: 2022/02/14 10:31:43 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*s_ptr;
	unsigned char	data;

	i = 0;
	data = (unsigned char)c;
	s_ptr = (unsigned char *)b;
	while (i < len)
	{
		s_ptr[i] = data;
		i++;
	}
	return (b);
}
