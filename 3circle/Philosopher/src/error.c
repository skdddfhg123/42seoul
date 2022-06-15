/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 23:49:42 by idongmin          #+#    #+#             */
/*   Updated: 2022/04/21 23:25:10 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	err_print(char *err)
{
	printf("%s", err);
	return (EXIT_FAILURE);
}

int	ft_free(t_data **data)
{
	int		i;

	// i = -1;
	// while (++i < (*data)->philo_num)
	// 	pthread_mutex_destroy((*data)->forks + i);
	// pthread_mutex_destroy(&((*data)->printer));
	if ((*data)->forks)
		free((*data)->forks);
	if ((*data)->philo)
		free((*data)->philo);
	free((*data));
	return (1);
}
