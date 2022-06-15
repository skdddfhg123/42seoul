/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 22:16:59 by idongmin          #+#    #+#             */
/*   Updated: 2022/03/16 04:37:07 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

static int	make_array(t_struct *test)
{
	test->array = ((long long *)malloc(sizeof(long long) * \
	test->A->currentElementCount));
	if (!test->array)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static void	push_all_element_to_array(t_struct *test)
{
	long long	tmp;
	int			i;

	i = 0;
	while (i < test->A->currentElementCount)
	{
		tmp = getLLElement(test->A, i)->data;
		test->array[i] = tmp;
		i++;
	}
}

static void	ascending_check(t_struct *test)
{
	int	i;

	i = 0;
	while (i < test->A->currentElementCount)
	{
		if (test->array[i] == getLLElement(test->A, i)->data)
			i++;
		else
			return ;
	}
	all_free(&test);
	exit(1);
}

int	argv_check(char *argv[], t_struct *test)
{
	int	i;

	i = 1;
	test->A = createLinkedList();
	test->B = createLinkedList();
	test->command = createLinkedList();
	while (1)
	{
		if (!argv[i])
			break ;
		if (ft_atoi_revised(argv[i], test))
			ft_error();
		i++;
	}
	test->p_second = test->A->currentElementCount - 1;
	if (make_array(test))
		ft_error();
	push_all_element_to_array(test);
	array_sort_and_overlap_check(test);
	if (test->p_first != 1)
		ascending_check(test);
	return (EXIT_SUCCESS);
}
