/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmlee <dongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 21:49:19 by dongmlee          #+#    #+#             */
/*   Updated: 2022/02/17 17:21:49 by dongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <string.h>

# include "./f_printf/ft_printf.h"
# include "./libft/libft.h"

# define BUFFSIZE 1024

typedef struct s_struct
{
	char	sum[BUFFSIZE];
	int		i;
	int		len;
}			t_struct;

t_struct	g_struct;

#endif