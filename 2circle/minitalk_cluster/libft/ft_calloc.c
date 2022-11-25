/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmlee <dongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 02:53:30 by dongmlee          #+#    #+#             */
/*   Updated: 2022/02/17 16:08:09 by dongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t		i;
	void		*arr;

	i = 0;
	arr = ((void *)malloc(size * count));
	if (!arr)
		return (0);
	ft_memset(arr, 0, count * size);
	return (arr);
}
