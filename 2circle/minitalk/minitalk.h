/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 21:49:19 by idongmin          #+#    #+#             */
/*   Updated: 2022/02/15 20:19:51 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>

# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"

# define BUFFSIZE 1024

typedef struct s_struct
{
	char			sum[BUFFSIZE];
	char			cha;
	int				i;
	int				len;
}					t_struct;

t_struct		g_struct;

#endif