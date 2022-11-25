/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmlee <dongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 11:58:16 by idongmin          #+#    #+#             */
/*   Updated: 2022/04/24 15:54:38 by dongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	flow_time(time_t time)
{
	time_t	start_time;

	start_time = get_time();
	while (get_time() - start_time < time)
		usleep(500);
}

static void	main_flow(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	print_philo(philo, "has taken a fork");
	pthread_mutex_lock(philo->r_fork);
	print_philo(philo, "has taken a fork");
	print_philo(philo, "is eating");
	philo->meal_time = get_time();
	flow_time(philo->data->eat_t);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

static void	*routine(void *argv)
{
	t_philo		*philo;

	philo = (t_philo *)argv;
	if (philo->idx % 2 == 0)
		usleep(philo->data->eat_t * 100);
	while (!philo->data->is_fin)
	{
		main_flow(philo);
		philo->cnt++;
		if (philo->cnt == philo->data->must_eat)
		{
			print_philo(philo, "FINISH!!!");
			philo->eat_done = 1;
			philo->data->fin_philo += 1;
			return (NULL);
		}
		print_philo(philo, "is sleeping");
		flow_time(philo->data->sleep_t);
		print_philo(philo, "is thinking");
	}
	return (NULL);
}

void	start(t_data *data)
{
	int	i;

	i = -1;
	data->fin_philo = 0;
	data->start_time = get_time();
	while (++i < data->philo_num)
	{
		(data->philo + i)->meal_time = get_time();
		if (pthread_create(&(data->philo + i)->thread, NULL, &routine, \
		(void *)(data->philo + i)) == -1)
			err_print("ERROR: Thread wasn't Created.\n");
		pthread_detach((data->philo + i)->thread);
		usleep(50);
	}
	if (pthread_create(&data->monitor, NULL, &monitor, data) == -1)
		err_print("ERROR: Thread wasn't Created.\n");
	while (!data->is_fin)
	{
		if (data->fin_philo == data->philo_num)
			data->is_fin = 1;
	}
	if (pthread_join(data->monitor, NULL) == -1)
		err_print("ERROR: 'pthread_join' Function didn't Work\n");
}
