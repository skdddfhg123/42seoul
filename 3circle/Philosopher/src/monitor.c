/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 11:59:56 by idongmin          #+#    #+#             */
/*   Updated: 2022/04/20 17:09:52 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*monitor(void *argv)
{
	t_data		*data;
	int			i;

	data = (t_data *)argv;
	while (!data->is_fin)
	{
		i = -1;
		while (++i < data->philo_num)
		{
			if (!(data->philo + i)->eat_done && \
			get_time() - (data->philo + i)->meal_time > data->die_t)
			{
				print_philo((data->philo + i), "die");
				data->is_fin = 1;
				break ;
			}
		}
	}
	return (NULL);
}
