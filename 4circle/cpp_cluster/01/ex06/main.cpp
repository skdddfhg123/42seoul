/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmlee <dongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 12:22:38 by idongmin          #+#    #+#             */
/*   Updated: 2022/09/07 16:07:50 by dongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av) {
	Harl Harl;

	if (ac != 2) {
		std::endl(std::cout << "Please enter as follows\n./Harl [SOMETHING]");
		return (0);
	}
	Harl.complain(av[1]);
	return (0);
}
