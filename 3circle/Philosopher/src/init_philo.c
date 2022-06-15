/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 03:26:15 by idongmin          #+#    #+#             */
/*   Updated: 2022/04/20 17:11:43 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	create_mutex(t_data *data)
{
	int			i;

	if (pthread_mutex_init(&(data->printer), NULL))
		return (err_print("ERROR: Mutex wasn't Created.\n"));
	if (pthread_mutex_init(&(data->eating), NULL))
		return (err_print("ERROR: Mutex wasn't Created.\n"));
	data->forks = malloc(sizeof(pthread_mutex_t) * (data->philo_num));
	if (!(data->forks))
		return (err_print("ERROR: Malloc Error\n"));
	i = -1;
	while (++i < (data->philo_num))
	{
		if (pthread_mutex_init(&(data->forks[i]), NULL))
			return (err_print("ERROR: Mutex wasn't Created.\n"));
	}
	return (EXIT_SUCCESS);
}

int	init_philo(t_data *data)
{
	int	i;

	data->philo = malloc(sizeof(t_philo) * (data->philo_num));
	if (!(data->philo))
		return (err_print("ERROR: Malloc Error\n"));
	if (create_mutex(data))
		return (EXIT_FAILURE);
	i = -1;
	while (++i < (data->philo_num))
	{
		data->philo[i].idx = i;
		data->philo[i].data = data;
		data->philo[i].is_die = 0;
		data->philo[i].eat_done = 0;
		data->philo[i].cnt = 0;
		data->philo[i].L_fork = &(data->forks[i]);
		data->philo[i].R_fork = &(data->forks[(i + 1) % data->philo_num]);
	}
	return (EXIT_SUCCESS);
}
