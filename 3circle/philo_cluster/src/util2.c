/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 12:01:14 by idongmin          #+#    #+#             */
/*   Updated: 2022/04/20 17:17:20 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long long	get_time(void)
{
	struct timeval	t;
	long long		res;

	gettimeofday(&t, NULL);
	res = t.tv_sec * 1000;
	res += t.tv_usec / 1000;
	return (res);
}

void	print_philo(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->data->printer);
	if (!philo->data->is_fin)
		printf("[%lld ms]   \t[%d]\t[%s]\n", \
			get_time() - philo->data->start_time, philo->idx + 1, str);
	pthread_mutex_unlock(&philo->data->printer);
}
