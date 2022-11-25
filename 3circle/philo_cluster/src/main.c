/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 23:18:43 by idongmin          #+#    #+#             */
/*   Updated: 2022/04/21 23:39:37 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	init_free(t_data **data)
{
	free((*data));
	(*data) = NULL;
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (init_data(argc, argv, &data))
		return (init_free(&data));
	if (init_philo(data))
		return (ft_free(&data));
	start(data);
	ft_free(&data);
	return (0);
}
