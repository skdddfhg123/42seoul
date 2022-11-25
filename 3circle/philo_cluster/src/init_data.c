/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 23:50:37 by idongmin          #+#    #+#             */
/*   Updated: 2022/04/22 11:43:26 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	arg_check(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc < 5 || argc > 6)
		return (err_print("ERROR : Wrong Argument Count\n"));
	i = 0;
	while (argv[++i])
	{
		j = 0;
		while (ft_isdigit(argv[i][j]))
			j++;
		if (ft_strlen(argv[i]) != j || argv[i][0] == '0')
			return (err_print("ERROR : Wrong Argument Value\n"));
	}
	return (EXIT_SUCCESS);
}

static int	put_in_data(int argc, char **argv, t_data **data)
{
	(*data)->philo_num = ft_atoi(argv[1]);
	(*data)->die_t = ft_atoi(argv[2]);
	(*data)->eat_t = ft_atoi(argv[3]);
	(*data)->sleep_t = ft_atoi(argv[4]);
	if ((*data)->philo_num < 1 || (*data)->philo_num > 200 \
	|| (*data)->eat_t < 60 || (*data)->sleep_t < 60 || (*data)->die_t < 60)
		return (EXIT_FAILURE);
	if (argc == 6)
		(*data)->must_eat = ft_atoi(argv[5]);
	else
		(*data)->must_eat = -1;
	(*data)->philo = NULL;
	(*data)->forks = NULL;
	(*data)->is_fin = 0;
	(*data)->fin_philo = 0;
	return (EXIT_SUCCESS);
}

int	init_data(int argc, char **argv, t_data **data)
{
	if (arg_check(argc, argv))
		return (EXIT_FAILURE);
	(*data) = malloc(sizeof(t_data));
	if (!(*data))
		return (err_print("ERROR: Malloc Error\n"));
	if (put_in_data(argc, argv, data))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
