/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:21:36 by idongmin          #+#    #+#             */
/*   Updated: 2022/03/15 19:31:15 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	initialization(t_struct *test)
{
	test->array = NULL;
	test->A = NULL;
	test->B = NULL;
	test->command = NULL;
	test->element.data = 0;
	test->element.pLLink = NULL;
	test->element.pRLink = NULL;
	test->p_first = 0;
	test->p_second = 0;
}

void	all_free(t_struct **test)
{
	deleteLinkedList((*test)->A);
	deleteLinkedList((*test)->B);
	deleteLinkedList((*test)->command);
	if ((*test)->array)
		free((*test)->array);
	free(*test);
	test = NULL;
}
