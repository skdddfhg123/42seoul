/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmlee <dongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 19:47:06 by dongmlee          #+#    #+#             */
/*   Updated: 2022/04/05 14:41:32 by dongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);

size_t	ft_g_strlen(const char	*s);
size_t	ft_g_strlcpy(char	*dest, const char	*src, size_t	size);

char	*ft_g_strdup(const char *s);
char	*ft_g_strchr(const char	*s, int c);
char	*ft_g_strjoin(char	*s1, char const	*s2);

#endif
