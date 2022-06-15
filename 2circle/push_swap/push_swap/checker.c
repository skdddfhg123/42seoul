/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 02:26:51 by idongmin          #+#    #+#             */
/*   Updated: 2022/03/16 04:35:56 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	checker_command(t_struct *test, char *file)
{
	if (!ft_strncmp(file, "pa", 2))
		c_pa(test->A, test->B);
	else if (!ft_strncmp(file, "pb", 2))
		c_pb(test->A, test->B);
	else if (!ft_strncmp(file, "sa", 2))
		c_sa(test->A);
	else if (!ft_strncmp(file, "sb", 2))
		c_sb(test->B);
	else if (!ft_strncmp(file, "ss", 2))
		c_ss(test->A, test->B);
	else if (!ft_strncmp(file, "ra", 2))
		c_ra(test->A);
	else if (!ft_strncmp(file, "rb", 2))
		c_rb(test->B);
	else if (!ft_strncmp(file, "rra", 3))
		c_rra(test->A);
	else if (!ft_strncmp(file, "rrb", 3))
		c_rrb(test->B);
	else if (!ft_strncmp(file, "rrr", 3))
		c_rrr(test->A, test->B);
	else if (!ft_strncmp(file, "rr", 2))
		c_rr(test->A, test->B);
	else
		ft_error();
	free(file);
}

static int	sort(t_struct *test)
{
	t_ListNode	*tmp;
	int			i;

	if (test->A->currentElementCount == 1)
		return (1);
	i = 1;
	tmp = getLLElement(test->A, 1);
	while (i < test->A->currentElementCount)
	{
		if (tmp->data != test->array[i++])
			return (0);
		tmp = tmp->pRLink;
	}
	return (1);
}

static void	ft_checker(t_struct *test)
{
	char	*file;

	while (1)
	{
		file = get_next_line(0);
		if (!file)
		{
			if (sort(test))
				ft_printf("OK\n");
			else
				ft_printf("KO\n");
			return ;
		}
		else
			checker_command(test, ft_strtrim(file, "\n"));
		free(file);
	}
}

int	main(int argc, char *argv[])
{
	t_struct	*test;

	if (argc < 2)
		ft_error();
	else
	{
		test = (t_struct *)malloc(sizeof(t_struct));
		if (!test)
			return (EXIT_FAILURE);
		initialization(test);
		test->p_first = 1;
		if (argv_check(argv, test))
			return (EXIT_FAILURE);
		ft_checker(test);
		all_free(&test);
		// system("leaks checker");
	}
	return (EXIT_SUCCESS);
}
