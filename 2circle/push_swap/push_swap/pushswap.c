/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 02:26:51 by idongmin          #+#    #+#             */
/*   Updated: 2022/03/16 04:29:15 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
		if (argv_check(argv, test))
			return (EXIT_FAILURE);
		if (test->p_second - test->p_first < 9)
			short_element_handler(test, test->p_first, test->p_second);
		else
			Ta_to_b(test, test->p_first, test->p_second);
		dispay_command(test);
		all_free(&test);
		// system("leaks push_swap");
	}
	return (EXIT_SUCCESS);
}
