/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 23:18:43 by idongmin          #+#    #+#             */
/*   Updated: 2022/04/21 23:28:10 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (init_data(argc, argv, &data))
		return (1);
	if (init_philo(data))
		return (ft_free(&data));
	start(data);
	printf("aa\n");
	ft_free(&data);
	// while (1)
	// 	;
	// system("leaks philo");
	return (0);
}
